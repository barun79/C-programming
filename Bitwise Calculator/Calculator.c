#include <stdio.h>

#define BITS  8

void ConvertDecimalToBinary(int number, char operand[BITS + 1]);

int main(){
    int operand_1, operand_2;
    char operand[3] ={};
    printf("Bitwise Calculator \n\n");
    printf("Enter two base 10 values with a bitwise operator to see the decimal result and the binary result. The format is \n\n"
    "FirstNumber BitwiseOperator SecondNumber \n\n"
    "For example, enter the expression\n\n"
    "This calculator can used with &, |, ^, << and >> \n\n"
    "Please note that the spaces between numbers and operator is essential " 
    "and the two entered values must be between 0 and 255 \n\n");

    printf("Enter expression ");
    scanf("%d%s%d", &operand_1, operand , &operand_2);
    while(operand_1 < 0 || operand_1 > 255 || operand_2 < 0 || operand_2 > 255){
        printf("The entered expression contains out of range values."
        "Please reenter the expression using the values between 0 and 255\n");
        printf("Enter expression ");
        scanf("%d%s%d", &operand_1, operand , &operand_2);
    }
 
    char operand1[BITS + 1] ={};
    char operand2[BITS + 1] ={};
    char result1[BITS + 1] = {};
    ConvertDecimalToBinary(operand_1, operand1);
    ConvertDecimalToBinary(operand_2, operand2);  
    int result ;
    switch (operand[0]){
        case '&':
            result = operand_1 & operand_2;
            break;
        case '|':
            result = operand_1 | operand_2;
            break;
        case '^':
            result = operand_1 ^ operand_2;
            break;
        case '<':
            result = operand_1 << operand_2;
            break;
        case '>':
            result = operand_1 >> operand_2;
            break;
        default:
            printf("The operator is not supported by this calculator\n");
    }
    if(operand[0] == '&' || operand[0] == '|' || operand[0] == '^' || operand[0] == '<' || operand[0] == '>'){
        ConvertDecimalToBinary(result, result1);
        printf("In base 10 ... \n");
        printf("%d %s %d = %d \n\n\n", operand_1, operand, operand_2, result); 
        printf("In %d-bit base 2 ...\n\n", BITS);
        printf("  %s\n%s\n  %s\n  ", operand1,operand,operand2);
        for(int i = 0; i < BITS; i++){
            printf("=");
        }
        printf("\n  %s\n", result1); 
    }
    return 0;
    
}


void ConvertDecimalToBinary(int number, char operand[BITS + 1 ]){
    int binary[BITS] = {};
    int counter = 0;
    while (number != 0){
        binary[counter] = number & 1;
        number = number >> 1;
        counter++;
    }
    for (int i = 0; i < BITS; i++){
        operand[i] = 48 + binary[BITS - 1 -i];
    }
}