
#include <stdio.h>
#include "DrawTool.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define size 20

void DrawCommand(char Map[][MAXMAPSIZE], int MyMapSize);

int main(void)
{
    char Map[MAXMAPSIZE][MAXMAPSIZE];
    int MyMapSize;

    InitializeMap(Map, &MyMapSize);
    PrintInstructions();
    PrintMap(Map, MyMapSize);
    DrawCommand(Map, MyMapSize);
    
    return 0;
}

void DrawCommand(char Map[][MAXMAPSIZE], int MyMapSize)
{
    char arrInput[size];
    char *Token = NULL;
    char *Delimiters = "(),";
    char inputCommand[size];
    int x, y, length;
    char mark;
    char Letter;

    
    printf("\nEnter draw command (Enter Q to quit) ");
    fgets(arrInput, size, stdin);
    printf("%s\n", arrInput);  

    
    Token = strtok(arrInput, Delimiters);
    strcpy(inputCommand, Token);
    Letter = toupper(inputCommand[0]);
    
    
    while (Letter != 'Q')
    {
        if (Letter == 'Q' || Letter == 'V' || Letter == 'H' || Letter == 'P')  
        {
            x = atoi(strtok(NULL, Delimiters));  
            y = atoi(strtok(NULL, Delimiters));  
            length = atoi(strtok(NULL, Delimiters));  
            Token = strtok(NULL, Delimiters); 
            if (Token[0] == '\0' || Token[0] == '\n')
            {
                mark = 'X';
            }
            else
            {
                mark = Token[0]; 
            }

            if (Letter == 'P' && x >= 0 && x < MyMapSize && y >= 0 && y < MyMapSize)
            {
                Map[x][y] = mark;
            }
            else if (Letter == 'H' && x >= 0 && y >=0 && length > 0 && (length + y) <= MyMapSize) 
            {
                DrawLine(Map, x, y, Letter, length, mark);
            }
            else if (Letter == 'V' && x >= 0 && y >=0 && length > 0 && (length + x) <= MyMapSize)
            {
                DrawLine(Map, x, y, Letter, length, mark);
            } 
            else
            {
                printf("That draw command is out of range");
            }
        }
        else
        {
            printf("\nThat draw command is unknown\n");
        }
        
        PrintMap(Map, MyMapSize);
        
        printf("\nEnter draw command (Enter Q to quit) ");
        fgets(arrInput, 20, stdin);
        printf("%s\n", arrInput);  

        
        Token = strtok(arrInput, Delimiters);
        strcpy(inputCommand, Token);
        Letter = toupper(inputCommand[0]);
        
    }
}
