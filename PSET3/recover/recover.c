#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//Define uint8_t from bmp.h resize file
typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    // Check for one command line argument
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // Assign pointer for memory card
    char *mcard = argv[1];

    // Check that memory card can be opened for reading
    FILE *input = fopen(mcard, "r");
    if (input == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", mcard);
        return 2;
    }

    //Allocate size of buffer
    uint8_t *buffer = malloc(512);

    //Allocate space for the file name
    char *image_name = malloc(8);

    // Initialize filenumber at 0
    int filenumber = 0;

    sprintf(image_name, "%03d.jpg", filenumber);

    // Open file and include writing permission
    FILE *img = fopen(image_name, "w");
    if (img == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", image_name);
        return 3;
    }

    //While loop to read through 512B blocks (if an item of size 'buffer' is not 1 then while loop stops(EOF))
    while (fread(buffer, sizeof(buffer), 1, input) == 1)
    {
        // Check if block contains header for JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            // Determine if this is the first JPEG or if another is open
            if (filenumber == 0)
            {
                // Write over garbage values (Feel like this would write over JPEG signature too--couldn't resolve though)
                fseek(img, 0, SEEK_CUR);

                // Initialize writing
                fwrite(buffer, sizeof(buffer), 1, img);

                //Increase filenumber to initialize subsequent if statement
                filenumber++;
            }

            if (filenumber > 0)
            {
                fclose(img);

                //Naming for [001.jpg] - [050.jpg]
                sprintf(image_name, "%03d.jpg", filenumber);

                // Open file and include writing permission
                FILE *img1 = fopen(image_name, "w");

                // Write 512 bytes at a time to restore JPEG
                fwrite(buffer, 512, 1, img1);

                filenumber ++;
            }
        }
        else
        {
            //Continue to write files when not header signature
            fwrite(buffer, sizeof(buffer), 1, img);
        }

    }

    fclose(input);
    free(buffer);
    free(image_name);
    return 0;
}
