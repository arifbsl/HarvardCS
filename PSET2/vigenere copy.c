// vigenere.c
// Encrypts user-supplied plaintext using a Vigenère cipher.

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Symbolic constant for alphabet size
#define ALPHABET 26

int main(int argc, string argv[])
{
    // Ensure proper usage
    if (argc != 2 || strlen(argv[1]) == 0)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }

    // Ensure keyword is valid
    int keylen = strlen(argv[1]);
    for (int i = 0; i < keylen; i++)
    {
        // Check that keyword is all letters
        if (!isalpha(argv[1][i]))
        {
            printf("invalid keyword\n");
            return 1;
        }

        // Capitalize keyword letters for later use
        argv[1][i] = toupper(argv[1][i]);
    }

    // Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");

    // Encrypt plaintext with keyword
    printf("ciphertext: ");
    int index = 0;
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            // Key is previously capitalized, this gives us rotation amount
            int key = argv[1][index] - 'A';

            // Handle uppercase plaintext characters
            if (isupper(plaintext[i]))
            {
                printf("%c", ((plaintext[i] - 'A' + key) % ALPHABET) + 'A');
            }

            // Handle lowercase plaintext characters
            else
            {
                printf("%c", ((plaintext[i] - 'a' + key) % ALPHABET) + 'a');
            }

            // Advance keyword position, wrapping if necessary
            index = (index + 1) % keylen;
        }

        // Handle other plaintext characters (which don't advance the key)
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
