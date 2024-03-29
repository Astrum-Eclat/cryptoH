#ifndef CRYPTOH_H
//Macros definitions
#define CRYPTOH_H
#define hashLogSize 36

#include <stddef.h>

char hashLog[hashLogSize] = { '0', '8', '2', '3', '4', '9', '1', '7', '6', '5', 'A', 'C', 'B', 'P', 'D', 'F', 'I', 'J', 'M', 'E', 'H', 'G', 'Y', 'K', 'Z', 'X', 'T', 'L', 'N', 'O', 'S', 'U', 'R','W','V','Q'};

//Function prototypes
char* hash(char* data, char* password, size_t len);

#endif