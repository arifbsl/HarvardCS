// recover.c
// Recovers JPGs

// Header files
#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define BYTEFF 0xff
#define BYTED8 0xd8
#define BLOCK 512
#define NAMELEN 8
#define STARTERLEN 3

// Type definition and global array of starter bytes
typedef uint8_t byte;
byte starters[] = {BYTEFF, BYTED8, BYTEFF};

// Function prototype
bool jpg_start(byte *buffer);

int main(int argc, string argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <card>\n", argv[0]);
        return 1;
    }

    // Open the card file
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Error: Cannot open %s.\n", argv[1]);
        return 2;
    }

    // Set aside a buffer to hold our jpeg bytes
    byte *buffer = malloc(sizeof(byte) * BLOCK);
    if (buffer == NULL)
    {
        fprintf(stderr, "Error: Memory failure.\n");
        fclose(inptr);
        return 3;
    }

    // Generic file pointer to be used for writing new jpegs
    FILE *outptr = NULL;
    int file_num = 0;

    // Set aside a buffer to hold our name string
    char *name = malloc(sizeof(char) * NAMELEN);
    if (name == NULL)
    {
        fprintf(stderr, "Error: Memory failure.\n");
        fclose(inptr);
        return 4;
    }

    // Continue reading blocks from the card until we reach the end
    while (fread(buffer, 1, sizeof(byte) * BLOCK, inptr) == BLOCK)
    {
        // Look for whether the first bytes of the jpg match
        if (jpg_start(buffer))
        {
            // If a file already is being written to, close it
            if (outptr != NULL)
            {
                fclose(outptr);
            }

            // Open a new file with the correct file number
            sprintf(name, "%03i.jpg", file_num++);
            outptr = fopen(name, "w");
            if (outptr == NULL)
            {
                fprintf(stderr, "Error: Cannot open %s.\n", name);
                fclose(inptr);
                return 5;
            }
        }

        // Continue writing to the file (if one is open), or ignore the block
        if (outptr != NULL)
        {
            fwrite(buffer, 1, sizeof(byte) * BLOCK, outptr);
        }
    }

    // All done, clean up all open files and allocated memory
    free(buffer);
    free(name);
    fclose(outptr);
    fclose(inptr);

    // That's all folks!
    return 0;
}

// Function to detect the beginning of a jpg, based on its initial four bytes
bool jpg_start(byte *buffer)
{
    // The first three bytes should be 0xff, 0xd8, 0xff
    if (!memcmp(buffer, starters, sizeof(byte) * STARTERLEN))
    {
        // Just a cute trick with bitwise operators to check the fourth byte
        return ((buffer[STARTERLEN] ^ 0x10) >= 0xf0) ? true : false;
    }

    // If you get to this point, you failed to match
    return false;
}
