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
        
        scanf("%d", &choice); // Read choice as an integer

        while (getchar() != '\n'); // Clear the buffer

        switch (choice) {
            case 1:
                scanf("%d", &numWords);
                getchar(); // Consume the newline character
                for (int i = 0; i < numWords; i++) {
                    scanf("%1023s", word); // Read a single word
                    getchar(); // Consume the newline character
                    StrList_insertLast(list, word);
                }
                break;
            case 2:
                scanf("%d", &index);
                while (getchar() != '\n'); // Clear the buffer
                fgets(word, sizeof(word), stdin); // Corrected to use 'word' instead of 'input'
                word[strcspn(word, "\n")] = 0; // Remove the newline character at the end of the input
                StrList_insertAt(list, word, index);
                break;
            case 3:
                StrList_print(list);
                printf("\n");
                break;
            case 4:
                printf("%zu\n", StrList_size(list));
                break;
            case 5:
                scanf("%d", &index);
                StrList_printAt(list, index);
                break;
            case 6:
                printf("%d\n", StrList_printLen(list));
                break;
            case 7:
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = 0; // Remove newline character
                printf("%d\n",StrList_count(list, word));
                break;
            case 8:
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = 0; // Remove newline character
                StrList_remove(list, word);
                break;
            case 9:
                scanf("%d", &index);
                getchar(); // Clear the buffer
                StrList_removeAt(list, index);
                break;
            case 10:
                StrList_reverse(list);
                break;
            case 11:
                StrList_free(list);
                list = StrList_alloc(); // Reallocate list to avoid using freed memory
                break;
            case 12:
                StrList_sort(list);
                break;
            case 13:
                if (StrList_isSorted(list)) {
                    printf("true\n");
                } else {
                    printf("false\n");
                }
                break;
                
            case 0:
                break;
            default:
        }
    } while (choice != 0);

    StrList_free(list); // Ensure to free the list before exiting
    return 0;
}
