#include "json_writer.h"
#include <stdio.h>


// Function to check if file exists
int file_exists(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        fclose(file);
        return 1;
    }
    return 0;
}

void write_json_file(char *file_name, char *json_string) {
    FILE *fp;
    int is_new_file = !file_exists(file_name);

    if (is_new_file) {
        // Create new JSON array
        fp = fopen(file_name, "w");
        fprintf(fp, "[\n%s\n]", json_string);
    } else {
        // Append new entry to existing JSON array
        fp = fopen(file_name, "r+"); // Open file for both reading and writing. The file must already exist
        fseek(fp, -2, SEEK_END); // Move to the position before the closing bracket
        fprintf(fp, ",\n%s\n]", json_string);
    }

    fclose(fp);
}

