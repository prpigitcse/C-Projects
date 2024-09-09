#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 1000
#define MAX_LEN 1000

struct Person {
    char first_name[100];
    char last_name[100];
    int age;
};

void parse_csv(FILE *fp, int *n, char header[]);
void display_csv_table(char header[], int n);

char line[MAX_LEN];
struct Person people[MAX_LINES];

int main(void) {
    FILE *fp;
    int n = 0;
    char header[MAX_LEN];

    printf("\n\033[1;33m --- CSV Reader ---\033[0m\n");
    
    fp = fopen("input.csv", "r");
    if(fp == NULL) {
        printf("\n\033[1;31m --- Error opening file. ---\033[0m\n");
        return 1;
    }

    parse_csv(fp, &n, header);
    fclose(fp);
    display_csv_table(header, n);

    return 0;
}

/* Function to parse CSV and store the result in a variable. */
void parse_csv(FILE *fp, int *n, char header[]) {
    _Bool header_line = 1;
    while (fgets(line, sizeof(line), fp) != NULL) {
        char first_name[100], last_name[100];
        int age;

        line[strcspn(line, "\n")] = '\0';

        if(header_line) {
            strcpy(header, line);
            header_line = 0;
            continue;
        }

        if(sscanf(line, "%[^,],%[^,],%d", first_name, last_name, &age) == 3) {
            strcpy(people[*n].first_name, first_name);
            strcpy(people[*n].last_name, last_name);
            people[*n].age = age;
            (*n)++;
        } else {
            printf("\n\033[1;31m --- Error parsing line. ---\033[0m\n");
        }
    }
}

/* Function to display CSV in tabular format */
void display_csv_table(char header[], int n) {
    char header_first_name[100], header_last_name[100], header_age[100];

    sscanf(header, "%[^,],%[^,],%s", header_first_name, header_last_name, header_age);

    printf("-----------------------|----------------------|-------------\n");
    printf("| %-20s | %-20s | %-10s |\n", header_first_name, header_last_name, header_age);
    printf("|----------------------|----------------------|------------|\n");
    for(int i = 0; i < n; i++) {
        printf("| %-20s | %-20s | %-10d |\n", people[i].first_name, people[i].last_name, people[i].age);
    }
    printf("-----------------------|----------------------|-------------\n");
}