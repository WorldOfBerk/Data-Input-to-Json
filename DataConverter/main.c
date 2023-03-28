#include <stdio.h>
#include "inp_validator.h"
#include "json_writer.h"

#define maximum_length 100

int main() {
    char name[maximum_length];
    char surname[maximum_length];
    char phoneNumber[maximum_length];
    char gender[maximum_length];
    //A variable for writing data to it
    char convert_to_json_string[maximum_length * 4];

    getString("Enter your name > ", name, maximum_length, validator_not_Empty);

    getString("Enter your surname > ", surname, maximum_length, validator_not_Empty);

    getString("Enter your phone number (start with + and must be 11 digits length) > ", phoneNumber, maximum_length, verification_phoneNumber);

    getString("Enter your gender as M-m or F-f > ", gender, maximum_length, verification_gender);

    sprintf(convert_to_json_string, "{\n\t\"Name\": \"%s\",\n\t\"Surname\": \"%s\",\n\t\"Phone Number\": \"%s\",\n\t\"Gender\": \"%s\"\n}",
            name, surname, phoneNumber, gender);

    //Writes converted to data.json
    write_json_file("data.json", convert_to_json_string);

    printf("Data successfully converted to JSON format!");

    return 0;
}
