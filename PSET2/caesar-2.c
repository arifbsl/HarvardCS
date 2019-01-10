#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //Check # of command line arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Verify command-line argument does not contain letters
    for (int x = 0, y = strlen(argv[1]); x < y; x++)
    {
        if (isalpha(argv[1][x]))
        {
            printf("Usage: ./caesar key\n");
            return 2;
            exit(0);
        }
    }
    //Convert int-like string values in key to ints
    int key = atoi(argv[1]);

    //Prompt for original text and output cipher
    string pt = get_string("plaintext: ");

    printf("ciphertext: ");

    //Iterate through chars until strlength of pt is reached
    for (int i = 0, n = strlen(pt); i < n; i++)
    {
        //Retain upper-case in ciphertext
        if (isupper(pt[i]))
        {
            int ptu = pt[i] - 65;
            printf("%c", ((ptu + key) % 26) + 65);
        }
        //Retain lower-case in ciphertext
        else if (islower(pt[i]))
        {
            int ptl = pt[i] - 97;
            printf("%c", ((ptl + key) % 26) + 97);
        }
        //Retain non-alphabetical characters
        else
        {
            printf("%c", pt[i]);
        }
    }
    printf("\n");
    return 0;
}
