
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void FillBingoCard(int arrBingo[][5]);
void printBingoCard(int arrBingo[][5]);
void printToFile(int arrBingo[][5], FILE *FIH);
int pickNumber(int arrCalled[75], int counter);
bool determineNum(int arrBingo[][5], int arrCalled[75], int counter);
bool completedRow(int arrBingo[][5]);
bool completedColumn(int arrBingo[][5]);
bool completedDiagonal(int arrBingo[][5]);

int main(void)
{
    int arrBingo[5][5];
    int arrCalled[75];
    char result;

    srand(time(0));
    //Call function to fill bingo card
    FillBingoCard(arrBingo);

    //Call function to print bingo card to screen
    printBingoCard(arrBingo);

    FILE *FIH = NULL;
    //Open a file named “BINGO.card” with w+ mode
    FIH = fopen("BINGO.card", "w+"); 

    if (FIH == NULL) 
    {
        printf("Error: Could not open file BINGO.card\n");
        return 1; 
    }

    //Call function to print bingo card to a file named “BINGO.card"
    printToFile(arrBingo, FIH);
    fclose(FIH);
    int counter = 0;
    bool row = false, column = false, diagonal = false;

    while ((counter < 75) && !(row) && !(diagonal) && !(column))
    {
        pickNumber(arrCalled, counter);
        
        printf("Do you have it? (Y/N) ");
        scanf(" %c", &result);
        printf("\n");
        if (result != 'Y')
        {
            printBingoCard(arrBingo);
        }
        else
        {
            if (determineNum(arrBingo, arrCalled, counter) == false)
            {
                printf("That value is not on your BINGO card - are you trying to cheat??\n\n");
                printBingoCard(arrBingo);
            }
            else
            {
                printBingoCard(arrBingo);
                row = completedRow(arrBingo);
                column = completedColumn(arrBingo);
                diagonal = completedDiagonal(arrBingo);

                if ((row && column && diagonal) == true)
                {  
                    printf("\nYou filled out a row and column and diagonal - BINGO!!!\n\n");
                }
                else if ((row && column) == true)
                {
                    
                    printf("\nYou filled out a row and column - BINGO!!!\n\n");
                }
                else if ((row && diagonal) == true)
                {
                    
                    printf("\nYou filled out a row and diagonal - BINGO!!!\n\n");
                }
                else if ((column && diagonal) == true)
                {           
                    printf("\nYou filled out a column and diagonal - BINGO!!!\n\n");
                }
                else if (row == true)
                {
                    
                    printf("\nYou filled out a row - BINGO!!!\n\n");
                }
                else if (column == true)
                {
                    
                    printf("\nYou filled out a column - BINGO!!!\n\n");
                }
                else if (diagonal == true)
                {
            
                    printf("\nYou filled out a diagonal - BINGO!!!\n\n");
                }
                
            }

        }
        counter++;
    }
    FIH = fopen("BINGO.card", "a");
    printToFile(arrBingo, FIH);
    
    for (int i = 0; i < counter; i++)
    {
        fprintf(FIH, "%d\t", arrCalled[i]);
        if ((i + 1) % 10 == 0)
        {
            fprintf(FIH, "\n");
        }
    }
    fclose(FIH);
    return 0;
}

void FillBingoCard(int arrBingo[][5])
{
    
    // fill unique number to BINGO card
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arrBingo[i][j] = rand() % 15 + (15 * i) + 1;
            int pass = 0;

            while (pass < j)
            {
                if (arrBingo[i][j] == arrBingo[i][pass])
                {
                    arrBingo[i][j] = rand() % 15 + (15 * i) + 1;
                    pass = 0;
                }
                else
                {
                    pass++;
                }          
            }
        }    
    }
    arrBingo[2][2] = 0;
}

void printBingoCard(int arrBingo[][5])
{
    
    printf("\n\n    B      I      N      G      O   \n");
    printf("------------------------------------\n");
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arrBingo[j][i] != 0)
            {
                printf("|  %2d  ", arrBingo[j][i]);
            }
            else
            {
                printf("|  %2c  ", 'X');
            }
        }
        printf("|\n------------------------------------\n");
        
    }   
}

void printToFile(int arrBingo[][5], FILE *FIH)
{
    fprintf(FIH, "       B            I            N            G            O   \n");
    fprintf(FIH, "------------------------------------------\n");
    
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arrBingo[j][i] != 0)
            {
                fprintf(FIH, "|    %3d    ", arrBingo[j][i]);
            }
            else
            {
                fprintf(FIH, "|    %3c    ", 'X');
            }
        }
        fprintf(FIH, "|\n------------------------------------------\n");
        
    }   
    fprintf(FIH, "\n\n");

}

int pickNumber(int arrCalled[75], int counter) 
{
    int loop = 0;
    int calledNum = rand() % (75 - 1 + 1) + 1;
    char letter;

    while (loop < counter)
    {
        if (calledNum == arrCalled[loop])
        {
            calledNum = rand() % (75 - 1 + 1) + 1;
            loop = 0;
        }
        else
        {
            loop++;
        }
    }
    
    arrCalled[counter] = calledNum;
    //finding corresponding letter
    if ((calledNum >= 1) && (calledNum <= 15))
    {
        letter = 'B';
    }
    else if ((calledNum >= 16) && (calledNum <= 30))
    {
        letter = 'I';
    }
    else if ((calledNum >= 31) && (calledNum <= 45))
    {
        letter = 'N';
    }
    else if ((calledNum >= 46) && (calledNum <= 60))
    {
        letter = 'G';
    }
    else if ((calledNum >= 61) && (calledNum <= 75))
    {
        letter = 'O';
    }
    printf("\nThe next number is %c%d\n\n", letter ,calledNum);
    return calledNum;
}

bool determineNum(int arrBingo[][5], int arrCalled[75], int counter)
{
    bool value = false;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arrBingo[i][j] == arrCalled[counter])
            {
                arrBingo[i][j] = 0;
                value = true;
            }
        }
    }
    return value;
}

bool completedColumn(int arrBingo[][5])
{
    bool isTrue = false;
    for (int i = 0; i < 5; i++)
    {
        if ((arrBingo[i][0] == 0) && (arrBingo[i][1] == 0) && (arrBingo[i][2] == 0) && (arrBingo[i][3] == 0) && (arrBingo[i][4] == 0))
        {
            isTrue = true;
        }
    }
    return isTrue;
}

bool completedRow(int arrBingo[][5])
{
    bool isTrue = false;
    for (int i = 0; i < 5; i++)
    {
        if ((arrBingo[0][i] == 0) && (arrBingo[1][i] == 0) && (arrBingo[2][i] == 0) && (arrBingo[3][i] == 0) && (arrBingo[4][i] == 0))
        {
            isTrue = true;
        }
    }
    return isTrue;
}

bool completedDiagonal(int arrBingo[][5])
{
    bool isTrue = false;
    if (((arrBingo[0][0] == 0) && (arrBingo[1][1] == 0) && (arrBingo[2][2] == 0) && (arrBingo[3][3] == 0) && (arrBingo[4][0] == 0)) || ((arrBingo[3][1] == 0) && (arrBingo[2][2] == 0) && (arrBingo[4][0] == 0) && (arrBingo[1][3] == 0) && (arrBingo[0][4] == 0)))
    {
        isTrue = true;
    }
    return isTrue;
}