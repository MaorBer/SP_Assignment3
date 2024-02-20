#include <stdio.h>
#include <stdlib.h>
#include "StrList.h"

int main() {
    StrList list;
    initializeList(&list);
    char choice;
    char input[100];
    int index;
    
    do {
        printf("\nMenu:\n");
        printf("1 - Insert strings into the list\n");
        printf("2 - Insert a string at a certain index\n");
        printf("3 - Print the list\n");
        printf("4 - Print the length of the list\n");
        printf("5 - Print a string at a certain index\n");
        printf("6 - Print the number of characters that appear in the entire list\n");
        printf("7 - Receive a string and print how many times it appears\n");
        printf("8 - Receive a string and delete all occurrences from the list\n");
        printf("9 - Receive an index and delete the corresponding member\n");
        printf("10 - Turn the list over\n");
        printf("11 - Deleting the entire list\n");
        printf("12 - Arrange the list according to lexicographical order\n");
        printf("13 - Check whether the list is arranged in lexicographic order\n");
        printf("0 - Exit the program\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        switch(choice) {
            case '1':
                printf("Enter strings to insert, separated by space: ");
                scanf("%s", input);
                insertAtEnd(&list, input);
                break;
            case '2':
                printf("Enter index and string to insert: ");
                scanf("%d %s", &index, input);
                insertAtIndex(&list, index, input);
                break;
            case '3':
                printf("List: ");
                printList(&list);
                break;
            case '4':
                printf("Length of list: %d\n", listLength(&list));
                break;
            case '5':
                printf("Enter index: ");
                scanf("%d", &index);
                printf("String at index %d: %s\n", index, getStringAtIndex(&list, index));
                break;
            // Implement other cases similarly
            case '0':
                clearList(&list);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != '0');
    
    return 0;
}
