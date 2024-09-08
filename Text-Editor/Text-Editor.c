#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 100
#define MAX_LEN 1000

void insert_text(int *n);
void delete_word(const char *word, int n);
void search_word(const char *word, int n);
void replace_word(const char *old_word, const char *new_word, int n);
void display_text(int n);
void free_text(int n);

char *text[MAX_LINES]; // Array of strings (pointer) to store multiple lines of text

int main(void) {
    int choice, n = 0;
    char word[MAX_LEN], new_word[MAX_LEN];

    do {
        printf("\n\033[1;33m--- Simple Text Editor ---\033[0m\n");
        printf("1. Insert Text.\n");
        printf("2. Delete Word.\n");
        printf("3. Search Word.\n");
        printf("4. Replace Word.\n");
        printf("5. Display Text.\n");
        printf("6. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline after the scanf

        switch (choice) {
            case 1:
                insert_text(&n);
                break;
            case 2:
                printf("Enter the word to delete: ");
                fgets(word, MAX_LEN, stdin);
                word[strcspn(word, "\n")] = '\0';
                delete_word(word, n);
                break;
            case 3:
                printf("Enter the word to search: ");
                fgets(word, MAX_LEN, stdin);
                word[strcspn(word, "\n")] = '\0';
                search_word(word, n);
                break;
            case 4:
                printf("Enter the word to replace: ");
                fgets(word, MAX_LEN, stdin);
                word[strcspn(word, "\n")] = '\0';
                printf("Enter the new word: ");
                fgets(new_word, MAX_LEN, stdin);
                new_word[strcspn(new_word, "\n")] = '\0';
                replace_word(word, new_word, n);
                break;
            case 5:
                display_text(n);
                break;
            case 6:
                free_text(n);
                printf("\n\033[1;33m--- Exiting ---\033[0m\n");
                break;
            default:
                printf("\n\033[1;31mInvalid Choice. Please try again.\033[0m\n");
        }
    } while(choice != 6);

    return 0;
}

/* Function to insert a line of text. */
void insert_text(int *n) {
    if (*n > MAX_LINES) {
        printf("Text limit reached.\n");
        return;
    }
    char buffer[MAX_LEN];
    printf("\n\033[1;37mEnter the line of text:\033[0m\n");
    fgets(buffer, MAX_LEN, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    text[*n] = (char *)malloc(strlen(buffer) + 1);
    strcpy(text[*n], buffer);
    (*n)++;
}

/* Function to display the text. */
void display_text(int n) {
    printf("\n\033[1;37mCurrent text:\033[0m\n");
    for(int i = 0; i < n; i++) printf("%s\n", text[i]);
}

/* Function to delete a word from the text */
void delete_word(const char *word, int n) {
    for(int i = 0; i < n; i++) {
        char *ptr = strstr(text[i], word);
        while (ptr) {
            // Use This block to remove space after the word
            // if(*(ptr + strlen(word)) == ' ')
            //     memmove(ptr, ptr + strlen(word) + 1, strlen(ptr + strlen(word)) + 1);
            // else 
            memmove(ptr, ptr + strlen(word), strlen(ptr + strlen(word)) + 1);
            ptr = strstr(text[i], word);
        }
    }
    printf("\033[1;37mWord \033[1;31m'%s'\033[0m deleted.\033[0m\n", word);
}

/* Function to search for a word in the text */
void search_word(const char *word, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (strstr(text[i], word)) {
            printf("\033[1;37m Word \033[1;35m'%s'\033[1;37m found in line %d: %s\033[0m\n", word, i+1, text[i]);
            found++;
        }
    }
    if(!found) printf("\033[1;31m Word '%s' not found.\033[0m\n", word);
}

/* Function to replace a word in the text */
void replace_word(const char *old_word, const char *new_word, int n) {
    for(int i = 0; i < n; i++) {
        char *ptr = strstr(text[i], old_word);
        while(ptr) {
            char buffer[MAX_LEN];
            strncpy(buffer, text[i], ptr-text[i]);
            buffer[ptr-text[i]] = '\0';
            strcat(buffer, new_word);
            strcat(buffer, ptr + strlen(old_word));

            free(text[i]);
            text[i] = (char *)malloc(strlen(buffer) + 1);
            strcpy(text[i], buffer);
            ptr = strstr(text[i], old_word);
        }
    }
    printf("\033[1;37mWord '%s' replaced with '%s'!\033[0m\n", old_word, new_word);
}

/* Function to free memory used by text. */
void free_text(int n) {
    for(int i = 0; i < n; i++) {
        free(text[i]);
    }
}