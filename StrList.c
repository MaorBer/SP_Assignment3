#include "StrList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

struct _StrList {
    Node *head;
};

// Allocate a new, empty StrList
StrList* StrList_alloc() {
    StrList* list = (StrList*)malloc(sizeof(StrList));
    if (!list) {
        fprintf(stderr, "Memory allocation failed for StrList\n");
        return NULL;
    }
    list->head = NULL;
    return list;
}

// Free the StrList and its contents
void StrList_free(StrList* list) {
    if (!list) return;
    Node* current = list->head;
    while (current) {
        Node* next = current->next;
        free(current->data); // Free the string
        free(current); // Then the node
        current = next;
    }
    free(list);
}

// Get the size of the StrList
size_t StrList_size(const StrList* list) {
    if (!list) return 0;
    size_t count = 0;
    for (Node* current = list->head; current; current = current->next) {
        count++;
    }
    return count;
}

// Insert a string at the end of the StrList
void StrList_insertLast(StrList* list, const char* data) {
    if (!list || !data) return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed for Node\n");
        return;
    }
    newNode->data = strdup(data);
    if (!newNode->data) {
        fprintf(stderr, "String duplication failed\n");
        free(newNode);
        return;
    }
    newNode->next = NULL;

    if (!list->head) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Insert a string at a specified index in the StrList
void StrList_insertAt(StrList* list, const char* data, int index) {
    if (!list || !data || index < 0 || index > StrList_size(list)) {
        fprintf(stderr, "Invalid operation: Invalid index or NULL data/list\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed for Node\n");
        return;
    }
    newNode->data = strdup(data);
    if (!newNode->data) {
        fprintf(stderr, "String duplication failed\n");
        free(newNode);
        return;
    }

    if (index == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        Node* current = list->head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Keep other functions as they are but apply similar checks for NULL pointers and ensure
// proper memory management, especially after operations like strdup fail.



char* StrList_firstData(const StrList* StrList) {
    if (StrList->head == NULL) {
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    return StrList->head->data;
}

void StrList_print(const StrList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* current = list->head;
    while (current != NULL) {
        printf("%s", current->data);
        if (current->next != NULL) printf(" "); // Add space between words, but not after the last word
        current = current->next;
    }
    printf("\n"); // Print newline at the end
}

void StrList_printAt(const StrList* StrList, int index) {
    if (index < 0 || index >= StrList_size(StrList)) {
        fprintf(stderr, "Invalid index\n");
        exit(EXIT_FAILURE);
    }
    Node* current = StrList->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    printf("%s\n", current->data);
}

int StrList_printLen(const StrList* StrList) {
    int totalLen = 0;
    Node* current = StrList->head;
    while (current != NULL) {
        totalLen += strlen(current->data);
        current = current->next;
    }
    return totalLen;
}

int StrList_count(StrList* StrList, const char* data) {
    int count = 0;
    Node* current = StrList->head;
    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            count++;
        }
        current = current->next;
    }
    return count;
}

void StrList_remove(StrList* StrList, const char* data) {
    Node* current = StrList->head;
    Node* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            if (prev == NULL) {
                StrList->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->data);
            free(current);
            current = prev == NULL ? StrList->head : prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void StrList_removeAt(StrList* StrList, int index) {
    if (index < 0 || index >= StrList_size(StrList)) {
        fprintf(stderr, "Invalid index\n");
        exit(EXIT_FAILURE);
    }
    Node* current = StrList->head;
    Node* prev = NULL;
    for (int i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }
    if (prev == NULL) {
        StrList->head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current->data);
    free(current);
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2) {
    Node* current1 = StrList1->head;
    Node* current2 = StrList2->head;
    while (current1 != NULL && current2 != NULL) {
        if (strcmp(current1->data, current2->data) != 0) {
            return 0;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return current1 == NULL && current2 == NULL;
}

StrList* StrList_clone(const StrList* list) {
    StrList* newList = StrList_alloc();
    Node* current = list->head; // Use the correct list variable
    while (current != NULL) {
        StrList_insertLast(newList, current->data);
        current = current->next;
    }
    return newList; // Ensure this return statement is present
}


void StrList_reverse(StrList* StrList) {
    Node* prev = NULL;
    Node* current = StrList->head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    StrList->head = prev;
}

void StrList_sort(StrList* StrList) {
    if (!StrList || !StrList->head || !StrList->head->next) return; // No need to sort if the list is empty or has one element

    Node *sorted = NULL, *current = StrList->head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        if (!sorted || strcmp(current->data, sorted->data) < 0) { // Insert before the sorted list
            current->next = sorted;
            sorted = current;
        } else {
            Node *temp = sorted;
            while (temp->next != NULL && strcmp(current->data, temp->next->data) >= 0) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    StrList->head = sorted; // Update head to the new sorted list
}


int StrList_isSorted(StrList* StrList) {
    Node* current = StrList->head;
    while (current != NULL && current->next != NULL) {
        if (strcmp(current->data, current->next->data) > 0) return 0; // Not sorted if current node data is greater than next node data
        current = current->next;
    }
    return 1; // Sorted
}


