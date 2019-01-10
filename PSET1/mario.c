#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for pyramid's height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Iterate over pyramid's rows
    for (int i = 0; i < height; i++)
    {
        // Iterate over pyramid's columns, width = height
        for (int j = 0; j < height; j++)
        {
            // Print spaces
            if (j < height - i - 1)
            {
                printf(" ");
            }

            // Print hashes
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
