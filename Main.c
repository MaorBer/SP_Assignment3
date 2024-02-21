#include <stdio.h>
#include <stdlib.h>
#include "StrList.h"

int main() {
    StrList* list = StrList_alloc();
    if (list == NULL) {
        fprintf(stderr, "Failed to allocate memory for the list\n");
        return EXIT_FAILURE;
    }

    char choice;
    char input[1024]; // Adjusted size for longer inputs
    int index, numWords;

    do {
        printf("\nMenu:\n");
        printf("A - Insert strings into the list\n");
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

        switch (choice) {
            case 'A':
                printf("Enter how many words you want to enter: ");
                scanf("%d", &numWords);
                while (getchar() != '\n'); // Clear the buffer
                for (int i = 0; i < numWords; i++) {
                    printf("Word %d: ", i + 1);
                    scanf("%s", input);
                    StrList_insertLast(list, input);
                }
                break;
            case '2':
                printf("Enter index and string to insert: ");
                scanf("%d", &index);
                while (getchar() != '\n'); // Clear the buffer
                scanf("%[^\n]", input); // This reads until a newline is encountered
                StrList_insertAt(list, input, index);
                break;
            case '3':
                StrList_print(list);
                break;
            case '4':
                printf("Length of list: %zu\n", StrList_size(list));
                break;
            case '5':
                printf("Enter index: ");
                scanf("%d", &index);
                StrList_printAt(list, index);
                break;
            case '6':
                printf("Total characters in the list: %d\n", StrList_printLen(list));
                break;
            case '7':
                printf("Enter a string to count: ");
                scanf("%s", input);
                printf("Occurrences of '%s': %d\n", input, StrList_count(list, input));
                break;
            case '8':
                printf("Enter a string to delete: ");
                scanf("%s", input);
                StrList_remove(list, input);
                break;
            case '9':
                printf("Enter index to delete: ");
                scanf("%d", &index);
                StrList_removeAt(list, index);
                break;
            case '10':
                StrList_reverse(list);
                break;
            case '11':
                StrList_free(list);
                list = StrList_alloc(); // Reallocate list to avoid using freed memory
                break;
            case '12':
                StrList_sort(list);
                break;
            case '13':
                if (StrList_isSorted(list)) {
                    printf("List is in lexicographical order.\n");
                } else {
                    printf("List is not in lexicographical order.\n");
                }
                break;
            case '0':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != '0');

    StrList_free(list); // Ensure to free the list before exiting
    return 0;
}
