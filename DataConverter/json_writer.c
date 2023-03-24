#include "json_writer.h"
#include <stdio.h>

void write_json_file(char *file_name, char *json_string) {
    FILE *fp;
    fp = fopen(file_name, "w");
    fprintf(fp, "%s\n", json_string);
    fclose(fp);
}

