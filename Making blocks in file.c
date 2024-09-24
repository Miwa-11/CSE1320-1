
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char fileName[100];
    char character;
    int i_start, i_end, j_start, j_end, k_start, k_end, block, linePerBlock, charPerLine;
    FILE *file = NULL;

    printf("Enter the file name: ");
    scanf("%s", fileName);
    file = fopen(fileName, "w");

    if (file == NULL)
    {
        printf("This file is not existing...\n");
        exit(0);
    }

    printf("Enter the character: ");
    scanf(" %c", &character);

    printf("Enter i's starting value: ");
    scanf("%d", &i_start);

    printf("Enter i's ending value: ");
    scanf("%d", &i_end);

    printf("Enter j's starting value: ");
    scanf("%d", &j_start);

    printf("Enter j's ending value: ");
    scanf("%d", &j_end);

    printf("Enter k's starting value: ");
    scanf("%d", &k_start);

    printf("Enter k's ending value: ");
    scanf("%d", &k_end);

    block = i_end - i_start;
    linePerBlock = j_end - j_start;
    charPerLine = k_end - k_start;

    for (int i = i_start; i < i_end; i++)
    {
        for (int j = j_start; j < j_end; j++)
        {
            for (int k = k_start; k < k_end; k++)
            {
                fprintf(file, "%c", character);
            }
            fprintf(file, "\n");
        }
        fprintf(file, "\n");
    }

    printf("Blocks: %d\n", block);
    
    printf("Lines per block: %d\n", linePerBlock);

    printf("Characters per line: %d\n", charPerLine);

    fclose(file);

    return 0;
   
}
