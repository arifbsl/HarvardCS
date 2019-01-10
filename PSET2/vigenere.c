#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int shift(char c);

int main(int argc, string argv[])
{
    //Check # of command line arguments
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    else
    {
        int key = shift(argv[1][0]);
        printf("%i\n", key);
        return 0;
    }

    //Verify command-line argument does not contain numbers
    for (int x = 0, y = strlen(argv[1]); x < y; x++)
    {
        if (isalpha(argv[1][x]))
        {
            printf("Usage: ./vigenere keyword\n");
            return 2;
            exit(0);
        }
    }
    //Convert int-like string values in key to ints
    int key = atoi(argv[1]);

    //Prompt for original text and output cipher
    string k = get_string("plaintext: ");

    printf("ciphertext: ");
            //Iterate through chars until strlength of pt is reached
    for (int i = 0, n = strlen(k); i < n; i++)
    {
        shift(1);
    }
}

int shift(char c)
{
    //Retain upper-case in ciphertext
    if (isupper(c))
    {
        int cu = c - 65;
        printf("%c", ((cu + key) % 26) + 65);
    }
    //Retain lower-case in ciphertext
    else if (islower(c))
    {
        int cl = c - 97;
        printf("%c", ((cl + key) % 26) + 97);
    }
    //Retain non-alphabetical characters
    else
    {
        printf("%c", (c));
    }
}
