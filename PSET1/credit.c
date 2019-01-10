#include <cs50.h>
#include <math.h>
#include <stdio.h>

#define MAX_LENGTH 16
#define AMEX_LENGTH 15
#define MIN_LENGTH 13

int main(void)
{
    // Obtain cc number from user
    long cc_num = get_long("Number: ");

    // Check to make sure card is not too long
    if (cc_num / (long) pow(10, MAX_LENGTH) != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Variables to hold length, running sum, and first two digits
    int checksum = 0;
    int length = 0;
    int first_digit = 0;

    // Sentinel value here, since a cc digit can never be -1
    int second_digit = -1;

    // Variable to track when we've started reading cc number
    bool started = false;

    // Iterate across all of the possible 16 digit places
    // reading left to right
    for (int i = MAX_LENGTH - 1; i >= 0; i--)
    {
        // Determine current digit value using division and mod
        long digit = (cc_num / (long) pow(10, i)) % 10;

        // If it's the second digit, log it
        if (started && second_digit == -1)
        {
            second_digit = digit;
        }

        // If it's the first digit, log it
        if (!started && digit != 0)
        {
            first_digit = digit;
            started = true;
            length = i + 1;
        }

        // Digits in "even" positions (those checked using odd powers of 10) double
        if ((i % 2) != 0)
        {
            // If the doubled value > 10, add the two digits together
            // the first digit is always 1 if this happens
            checksum += (digit < 5) ? (2 * digit) : ((2 * digit) % 10) + 1;
        }
        else
        {
            checksum += digit;
        }
    }

    // Check to make sure card is not too short
    if (length < MIN_LENGTH)
    {
        printf("INVALID\n");
    }

    // Check to make sure checksum is valid
    else if ((checksum % 10) != 0)
    {
        printf("INVALID\n");
    }

    // Perform VISA checks (starts with 4, is either 13 or 16 digits)
    else if (first_digit == 4 && (length == MIN_LENGTH || length == MAX_LENGTH))
    {
        printf("VISA\n");
    }

    // Perform MASTERCARD check (starts with 50-55, is 16 digits)
    else if (first_digit == 5 && (second_digit >= 0 && second_digit <= 5) && length == MAX_LENGTH)
    {
        printf("MASTERCARD\n");
    }

    // Perform AMEX check (starts with 34 or 37, is 15 digits)
    else if (first_digit == 3 && (second_digit == 4 || second_digit == 7) && length == AMEX_LENGTH)
    {
        printf("AMEX\n");
    }

    // Otherwise must not be MASTERCARD, VISA, or AMEX
    printf("INVALID\n");
    return 0;
}
