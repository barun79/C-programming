#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_numbers (int numbers[5][5]);
void print_numbers(int numbers[5][5]);

int main(){
    int numbers [5][5];
    srand(time(0));
    fill_numbers(numbers);
    print_numbers(numbers);

    return 0;
}

void fill_numbers(int numbers[5][5]){
    int duplicate[25];
    int number;
    for( int i = 0; i < 5; i++){
        for (int j = 0; j < 5 ; j++){
            number = (rand() % 15 + 1) + i*15;
            for(int k = 0; k < j; k++){
                while(number == duplicate[(i* 5) + k]){
                    number = (rand() % 15 + 1) + i*15;
                    k = 0;
                }
            }
            duplicate[ (i*5) + j] = number;
            numbers[j][i] = number;
        }
    }
}

void print_numbers(int numbers[5][5]){

    printf("    B       I       N       G       0   \n");
    for (int i = 0; i < 5; i++ ){
        printf("--------");
    }
        printf("\n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("|%4d   ", numbers[i][j]);
        }
        printf("\n");
        for (int i = 0; i < 5; i++ ){
            printf("--------");
        }
        printf("\n");
    }
}