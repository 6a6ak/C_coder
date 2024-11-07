#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "functions/function01.h"  

void list_files(const char *folder_path) {
    struct dirent *entry;
    DIR *dir = opendir(folder_path);
    int file_count = 1;

    if (dir == NULL) {
        printf("Could not open directory: %s\n", folder_path);
        return;
    }

    printf("List of .h files in folder '%s':\n", folder_path);
    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".h") != NULL) {
            printf("%d. %s\n", file_count, entry->d_name);
            file_count++;
        }
    }
    closedir(dir);
}

int main() {
    const char *folder_path = "functions";
    char header_file[100];

    // list of functions
    list_files(folder_path);

    // get right name of function
    printf("Enter the exact file name (with .h extension) to execute: ");
    scanf("%s", header_file);

    // call function
    print_message();

    return 0;
}
//test