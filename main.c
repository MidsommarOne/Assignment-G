#include <stdio.h>
#include <ctype.h>
#include "main.h"

void verifyPersonnummer(uint8_t arr[PERSONNUMMER_LENGTH])
{
    uint8_t tmp = 0;
    uint8_t sum = 0;
    uint8_t control_digit = 0;
    //Luhn Algorithm on all digits but the last(control)
    for (int i = 0; i < (PERSONNUMMER_LENGTH - 1); i++)
    {
        tmp = arr[i] * (2 - i % 2); //value - 1 or 2
        if (tmp >= 10)
        {
            tmp -= 9;
        }
        sum += tmp;
    }

    control_digit = (10 - sum % 10);

    //Check if control digit is equal to our calculated control digit
    if (arr[9] == control_digit)
    {
        printf("Control succeded");
    }
    else
    {
        printf("Control failed");
    }
}

void convertFromASCII(uint8_t arr[MAX_INPUT_LENGTH], uint8_t pnr[PERSONNUMMER_LENGTH])
{
    int j = 0;

    for (int i = 0; i < MAX_INPUT_LENGTH; i++)
    {
        if (isdigit(arr[i]))
        {
            pnr[j++] = arr[i] - '0';
        }
    }
}

int main(void)
{
    printf("YYMMDD-nnnn: ");
    uint8_t pnr[PERSONNUMMER_LENGTH] = {0};
    uint8_t input[MAX_INPUT_LENGTH] = {0};

    fgets(input, MAX_INPUT_LENGTH, stdin);

    convertFromASCII(input, pnr);
    verifyPersonnummer(pnr);

    return 0;
}