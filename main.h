#ifndef MAIN_H
#define MAIN_H
#include <stdint.h>

#define PERSONNUMMER_LENGTH 10
#define MAX_INPUT_LENGTH 12

void verifyPersonnummer(uint8_t pnr[PERSONNUMMER_LENGTH]);
void convertFromASCII(uint8_t input[MAX_INPUT_LENGTH], uint8_t output[PERSONNUMMER_LENGTH]);
#endif