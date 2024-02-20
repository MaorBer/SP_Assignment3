#include "StrList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _StrList {
    Node *head;
};

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

StrList* StrList_alloc() {
    StrList* list = (StrList*)malloc(sizeof(StrList));
    if (list == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    return list;
}

void StrList_free(StrList* StrList) {
    if (StrList == NULL) return;
    Node* current = StrList->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(StrList);
}

size_t StrList_size(const StrList* StrList) {
    size_t count = 0;
    Node* current = StrList->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void StrList_insertLast(StrList* StrList, const char* data) {
    // Parse the input string to extract individual words
    const char* delimiter = " ";
    char* token = strtok((char*)data, delimiter);

    while (token != NULL) {
        // Allocate memory for the new node
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        // Allocate memory and copy the word into the new node
        newNode->data = strdup(token);
        newNode->next = NULL;

        // If the list is empty, set the new node as the head
        if (StrList->head == NULL) {
            StrList->head = newNode;
        } else {
            // Traverse the list to find the last node
            Node* current = StrList->head;
            while (current->next != NULL) {
                current = current->next;
            }
            // Append the new node to the end of the list
            current->next = newNode;
        }

        // Move to the next word
        token = strtok(NULL, delimiter);
    }
}


void StrList_insertAt(StrList* StrList, const char* data, int index) {
    if (index < 0 || index > StrList_size(StrList)) {
        fprintf(stderr, "Invalid index\n");
        exit(EXIT_FAILURE);
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = strdup(data);

    if (index == 0) {
        newNode->next = StrList->head;
        StrList->head = newNode;
    } else {
        Node* current = StrList->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

char* StrList_firstData(const StrList* StrList) {
    if (StrList->head == NULL) {
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }
    return StrList->head->data;
}

void StrList_print(const StrList* StrList) {
    Node* current = StrList->head;
    while (current != NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
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

StrList* StrList_clone(const StrList* StrList) {
    StrList* newList = StrList_alloc();
    Node* current = StrList->head;
    while (current != NULL) {
        StrList_insertLast(newList, current->data);
        current = current->next;
    }
    return newList;
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
    // Sorting algorithm goes here
}

int StrList_isSorted(const StrList* StrList) {
    // Check if the list is sorted
}
