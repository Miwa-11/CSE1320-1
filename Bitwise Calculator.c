
#include <stdio.h>

#define BITS 8

void ConvertDecimalToBinary(int decimalValue, char arr1[])
{
    int divide2arr[BITS];

    for(int i = 0; i < BITS; i++)
    {
        divide2arr[i] = decimalValue >> i;
        divide2arr[i] = divide2arr[i] & 1; 
        arr1[BITS-i-1] =  (char)(divide2arr[i] + '0');
    } 
    
}


int main()
{
    char input_arr[3];
    char left_binary[BITS+1] = {};
    char right_binary[BITS+1] = {};
    int right;
    int left;
    char result[BITS+1] = {};

    printf("Bitwise Calculator\n\nEnter two base 10 values with a bitwise operator to see the decimal result\n");
    printf("and the binary result. The format is\n\nFirstNumber BitwiseOperator SecondNumber\n\nFor example, enter the expression\n\n");
    printf("2 & 3\n\nThis calculator can used with &, |, ^, << and >>\n\nPlease note that the spaces between numbers and operator is essential\n");
    printf("and the two entered values must be between 0 and 255\n\nEnter expression ");
    scanf("%d %s %d", &left, input_arr, &right);
    printf("\n");

    while (!(0 <= right && right <= 255) || !(0 <= left && left <= 255))
    {
        printf("The entered expression contains out of range values.\nPlease reenter the expression using values between 0 and 255.\n\n");
        scanf("%d %s %d", &left, input_arr, &right);
        printf("\n");
    }
    ConvertDecimalToBinary(left, left_binary);
    ConvertDecimalToBinary(right, right_binary);

    switch (input_arr[0])
    {
        case '&':
        
            printf("In base 10...\n\n");
            printf("%d %s %d = %d\n\n\n", left, input_arr, right, left & right);
            printf("In %d-bit base 2...\n\n", BITS);
            printf("%10s\n", left_binary);
            printf("%s\n", input_arr);
            printf("%10s\n", right_binary);
            printf("  ========\n");
            for (int i = 0; i < BITS; i++)
            {
                result[i] = ((left_binary[i] - '0') & (right_binary[i] - '0')) + '0';
            }
            printf("%10s\n\n", result);
            break;

        case '|':

            printf("In base 10...\n\n");
            printf("%d %s %d = %d\n\n\n", left, input_arr, right, left | right);
            printf("In %d-bit base 2...\n\n", BITS);
            printf("%10s\n", left_binary);
            printf("%s\n", input_arr);
            printf("%10s\n", right_binary);
            printf("  ========\n");
            for (int i = 0; i < BITS; i++)
            {
                result[i] = ((left_binary[i] - '0') | (right_binary[i] - '0')) + '0';
            }
            printf("%10s\n\n", result);    
            break;

        case '^':
            
            printf("In base 10...\n\n");
            printf("%d %s %d = %d\n\n\n", left, input_arr, right, left ^ right);
            printf("In %d-bit base 2...\n\n", BITS);
            printf("%10s\n", left_binary);
            printf("%s\n", input_arr);
            printf("%10s\n", right_binary);
            printf("  ========\n");
            for (int i = 0; i < BITS; i++)
            {
                result[i] = ((left_binary[i] - '0') ^ (right_binary[i] - '0')) + '0';
            }
            printf("%10s\n\n", result);
            break;
        
        case '<':

            printf("In base 10...\n\n");
            printf("%d %s %d = %d\n\n\n", left, input_arr, right, left << right);
            printf("In %d-bit base 2...\n\n", BITS);
            printf("%s   ", left_binary);
            printf("%s", input_arr);
            printf("  %d\n\n", right);
            for (int i = 0; i < BITS - right; i++)
            {
                result[i] = left_binary[right + i];
            }
            for (int i = 0; i < right; i++)
            {
                result[BITS-right+i] = '0';
            }
            printf("%s\n\n", result);
            break;
        
        case '>':

            printf("In base 10...\n\n");
            printf("%d %s %d = %d\n\n\n", left, input_arr, right, left >> right);
            printf("In %d-bit base 2...\n\n", BITS);
            printf("%s   ", left_binary);
            printf("%s", input_arr);
            printf("  %d\n\n", right);
            for (int i = 0; i < BITS-right; i++)
            {
                result[right+i] = left_binary[i];
            }
            for (int i = 0; i < right; i++)
            {
                result[i] = '0';
            }
            printf("%s\n\n", result);

            break;
        
        default:
            printf("Operator %c is not supported by this calculator\n\n", input_arr[0]);
            
    }

    return 0;
    
}
