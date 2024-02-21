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
    char input[1024]; // Buffer for input strings
    int index;

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
        printf("13 - Check whether the list is arranged in lexicographical order\n");
        printf("0 - Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read choice as an integer

        while (getchar() != '\n'); // Clear the buffer

        switch (choice) {
            case 1:
                printf("Enter strings separated by space (end with newline): ");
                fgets(input, sizeof(input), stdin); // Use fgets to read the string including spaces
                char *word = strtok(input, " \n");
                while (word != NULL) {
                    StrList_insertLast(list, word);
                    word = strtok(NULL, " \n");
                }
                break;
            case 2:
                printf("Enter index and string to insert: ");
                scanf("%d", &index);
                while (getchar() != '\n'); // Clear the buffer
                fgets(input, sizeof(input), stdin); // Read the string to insert
                // Remove the newline character at the end of the input
                input[strcspn(input, "\n")] = 0;
                StrList_insertAt(list, input, index);
                break;
            // Implement other cases similarly based on the specified rules...
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
            // Continue with cases 6-13 as per your logic...
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
