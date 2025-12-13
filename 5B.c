#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    char filename[20];
    scanf("%s", filename);

    FILE *inFile = fopen(filename, "r");
    if (inFile == NULL) 
    {
        return 0;
    }

    int freq[256] = {0};
    int pixelVal;

    while (fscanf(inFile, "%2x", &pixelVal) == 1)
    {
        if (pixelVal >= 0 && pixelVal <= 255) 
        {
            freq[pixelVal]++;
        }
    }
    fclose(inFile);

    int maxFreq = 0;
    int maxPixel = -1;

    for (int i = 0; i < 256; i++) 
    {
        if (freq[i] > maxFreq) 
        {
            maxFreq = freq[i];
            maxPixel = i;
        }
    }

    
    if (maxPixel != -1) 
    {
        FILE *outFile = fopen("output.txt", "a");
        if (outFile != NULL) 
        {
            fprintf(outFile, "%2X %d\n", maxPixel, maxFreq);
            fclose(outFile);
        }
    }

    return 0;
}


5009