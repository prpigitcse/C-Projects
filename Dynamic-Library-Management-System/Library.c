#include <stdio.h>
#include <stdbool.h>

struct Book {
    char *title;
    char *author;
    char *ISBN;
    bool availability;
};

struct Library {
    struct Book *book;
    int size;
    int capacity;
};

void add_book();
void edit_book();
void delete_book();
void search_book_by_title();
void sort_books_by_title();
void free_memory();

int main(void) {
    FILE *fp;
    int op;
    
    fp = fopen("library.csv", "a+");
    if(fp == NULL) {
        printf("\n\033[1;31m --- Error opening file. ---\033[0m\n");
        return 1;
    }

    do {
        printf("\n\033[1;33m--- Dynamic Library Management System ---\033[0m\n");
        printf("1. Add Book.\n");
        printf("2. Edit Book Details.\n");
        printf("3. Delete Book.\n");
        printf("4. Search Book By Title.\n");
        printf("5. Sort Books By Title.\n");
        printf("6. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                add_book();
                break;
            case 2:
                edit_book();
                break;
            case 3:
                delete_book();
                break;
            case 4:
                search_book_by_title();
            case 5:
                sort_books_by_title();
                break;
            case 6:
                free_memory();
                break;
        }

    } while(op != 6);

    return 0;
}
