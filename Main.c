#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

int main() {
    StrList* list = StrList_alloc();
    if (list == NULL) {
        fprintf(stderr, "Failed to allocate memory for the list\n");
        return EXIT_FAILURE;
    }

    int choice;
    char word[1024]; // Buffer for input words
    int numWords, index;

    do {
        printf("\nMenu:\n");
        printf("1 - Insert strings into the list\n");
        printf("2 - Insert a string at a certain index\n");
        printf("3 - Print the list\n");
        printf("4 - Print the length of the list\n");
        printf("5 - Print a string at a certain index\n");
        printf("6 - Print the number of characters that appear in the entire list\n");
        printf("7 - Get a string and print how many times it appears\n");
        printf("8 - Get a string and delete all occurrences from the list\n");
        printf("9 - Get an index and delete the corresponding member\n");
        printf("10 - Turn the list over\n");
        printf("11 - Deleting the entire list\n");
        printf("12 - Arrange the list according to lexicographical order\n");
        printf("13 - Check whether the list is arranged in lexicographic order\n");
        printf("0 - Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read choice as an integer

        while (getchar() != '\n'); // Clear the buffer

        switch (choice) {
            case 1:
                printf("Enter the number of words you want to enter: ");
                scanf("%d", &numWords);
                getchar(); // Consume the newline character
                getline(&word,&numWords,stdin);
                StrList_insertLast(list, word);
                
                break;
            case 2:
                printf("Enter index and string to insert: ");
                scanf("%d", &index);
                while (getchar() != '\n'); // Clear the buffer
                fgets(word, sizeof(word), stdin); // Corrected to use 'word' instead of 'input'
                word[strcspn(word, "\n")] = 0; // Remove the newline character at the end of the input
                StrList_insertAt(list, word, index);
                break;
            case 3:
                StrList_print(list);
                break;
            case 4:
                printf("Length of list: %zu\n", StrList_size(list));
                break;
            case 5:
                printf("Enter index: ");
                scanf("%d", &index);
                StrList_printAt(list, index);
                break;
            case 6:
                printf("Total characters in the list: %d\n", StrList_printLen(list));
                break;
            case 7:
                printf("Enter a string to count: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = 0; // Remove newline character
                printf("Occurrences of '%s': %d\n", word, StrList_count(list, word));
                break;
            case 8:
                printf("Enter a string to delete all occurrences: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = 0; // Remove newline character
                StrList_remove(list, word);
                break;
            case 9:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                getchar(); // Clear the buffer
                StrList_removeAt(list, index);
                break;
            case 10:
                StrList_reverse(list);
                printf("List reversed.\n");
                break;
            case 11:
                StrList_free(list);
                list = StrList_alloc(); // Reallocate list to avoid using freed memory
                printf("List deleted.\n");
                break;
            case 12:
                StrList_sort(list);
                printf("List arranged in lexicographical order.\n");
                break;
            case 13:
                if (StrList_isSorted(list)) {
                    printf("The list is arranged in lexicographical order.\n");
                } else {
                    printf("The list is not arranged in lexicographical order.\n");
                }
                break;
                
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    StrList_free(list); // Ensure to free the list before exiting
    return 0;
}
