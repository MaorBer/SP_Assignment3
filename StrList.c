#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

void initializeList(StrList *list) {
    list->head = NULL;
}

void insertAtEnd(StrList *list, const char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = strdup(data);
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Implement other functions similarly
