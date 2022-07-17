#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
 /* open memory card
    look for beginning of a JPEG
    open a new JPEC file
    write 512 bytes until a new JPEG is found */

    if (argc != 2)
    {
        printf("./recover IMAGE\n");
        return 1;
    }
    char *infile = argv[1];
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

     /* open memory card
    look for beginning of a JPEG
    open a new JPEC file
    write 512 bytes until a new JPEG is found */

    BYTE buffer[512];
    int countImage = 0;
    bool firstJPEG = false;
    bool foundJPEG = false;
    size_t readsize;
    FILE *outputFile;
    char filename[100];

    // repeat until end of card

    while (true)
    {
    //      read 512 bytes into a buffer
        readsize = fread(buffer, sizeof(BYTE), 512, inptr);
        if (readsize == 0)
        {
            break;
        }
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            foundJPEG = true;
            if (!firstJPEG)
            {
                firstJPEG = true;

            }
            else
            {
                fclose(outputFile);
            }
            sprintf(filename, "%03i.jpg", countImage);
            outputFile = fopen(filename, "w");
            fwrite(buffer, sizeof(BYTE), readsize, outputFile);
            countImage++;

        }
        else
        {
            if(foundJPEG)
            {
                fwrite(buffer, sizeof(BYTE), readsize, outputFile);
            }
        }
    }
    fclose(inptr);
    fclose(outputFile);
}
    //      if start of new JPEG
    //          if first JPEG
    //              ....
    //          else
    //              ....
    //      else
    //          if already found JPEG
    //              ....




    // while (fread(buffer, sizeof(char), 512, inptr))
    // {
    //     if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    //     {
    //         sprintf(filename, "%03i.jpg", count_image);

    //          outputfile = fopen(filename, "w");
    //          count_image++;
    //     }
    //     if(outputfile != NULL)
    //     {
    //         fwrite(buffer, sizeof(char), 512, outputfile);
    //     }
    // }
    // free(filename);
    // fclose(outputfile);
    // fclose(inptr);

    // return 0;
