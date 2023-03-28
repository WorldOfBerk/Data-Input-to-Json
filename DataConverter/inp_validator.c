#include "inp_validator.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Check if entered string contains only digits
int is_digit(char *str){
    for (int i = 0; i < strlen(str); i++)
    {
        if(!isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1;
}

void getString(char *entry, char *string, int max_Length, int (*verification)(char*)){
    do {
        printf("%s", entry);
        fgets(string, max_Length, stdin);
        string[strcspn(string, "\n")] = 0;
        if(!verification(string))
        {
            printf("Invalid input. Try Again!");
        }
    } while (!verification(string));
}
//Function for gender verification. It is not case sensitive
int verification_gender(char *string){
    if(strlen(string) == 0){
        return 0;
    }
    //Comparison without sensivity to case
    if(strcasecmp(string, "M") != 0 && strcasecmp(string, "F") != 0){
        return 0;
    }
    return 1;
}
//Function for phone number verification, it should start with "+" sign
int verification_phoneNumber(char *string){
    if(strlen(string) == 0){
        return 0;
    }
    if(string[0] != '+' || strlen(string) != 11 || !is_digit(string + 1)){
        return 0;
    }
    return 1;
}
//Checks if string is not empty
int validator_not_Empty(char *string){
    return strlen(string) > 0;
}