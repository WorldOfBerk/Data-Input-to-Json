#ifndef DATACONVERTER_INP_VALIDATOR_H
#define DATACONVERTER_INP_VALIDATOR_H

void getString(char* entry, char* string, int max_Length, int (*verification)(char*));

int verification_gender(char *string);

int verification_phoneNumber(char *string);

int validator_not_Empty(char *string);

#endif //DATACONVERTER_INP_VALIDATOR_H
