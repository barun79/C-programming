#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void fill_numbers (int numbers[5][5]);
void print_numbers(int numbers[5][5]);
int pick_number(int *count, int picked_number[75]);
// void check_duplicate_pick(int picked_number[75]);
bool number_exist(int numbers[5][5], int pick);
int check_row(int numbers[5][5]);
int check_column(int numbers[5][5]);
int check_diagonal(int numbers[5][5]);

int main(){
    int numbers [5][5];
    int picked_number[75];
    int count = 0;
    srand(time(0));
    fill_numbers(numbers);
    print_numbers(numbers);
    bool bingo = false;
    while(!bingo){
        int pick = pick_number(&count, picked_number);
        bool exist = number_exist(numbers, pick);
        if (exist){
            print_numbers(numbers);
        }
        int row = check_row(numbers);
        int column = check_column(numbers);
        int diagonal = check_diagonal(numbers);
        if (row + column + diagonal > 4){
            bingo = true;
            printf("You won.\nRows %d Columns %d Diagonals %d \n", row, column, diagonal);
        }
    }

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
            if(numbers[i][j] == 0){
                printf("|   X   ");
            }
            else{
                printf("|%4d   ", numbers[i][j]);
            }
        }
        printf("\n");
        for (int i = 0; i < 5; i++ ){
            printf("--------");
        }
        printf("\n");
    }
    printf("\n");
}

int pick_number(int *count, int picked_number[75]){
    int pick = rand() % 75 + 1;
    for (int i = 0; i < *count ; i++){
        while(pick ==picked_number[i]){
            pick = rand() % 75 + 1;
            i = 0;
        }
    }
    picked_number[*count] = pick;
   (*count)++;
    return pick;
}

bool number_exist(int numbers[5][5], int pick){
    bool found = false;
    for (int i = 0; i < 5 ; i++){
        for (int j = 0; j < 5 ; j++){
            if ( pick == numbers[i][j]){
                numbers[i][j] = 0;
                found = true;
                goto endloop;
            }
        }
    }
    endloop:
    return found;
}

int check_row (int numbers[5][5]){
    int row = 0;
    for(int i = 0 ; i < 5 ; i++){
        int count = 0;
        for (int j = 0 ; j < 5; j++){
            if (numbers[i][j]== 0){
                count++;
            }
        }
        if (count == 5){
            row++;
        }
    }
    return row;
}

int check_column(int numbers[5][5]){
    int column = 0;
    for(int i = 0; i < 5; i++){
        int count = 0;
        for(int j = 0; j < 5 ; j++){
            if(numbers[j][i] == 0){
                count++;
            }
        }
        if(count == 5){
            column++;
        }
    }
    return column;
}

int check_diagonal(int numbers[5][5]){
    int diagonal = 0;
    int mcount = 0;
    int acount = 0;
    for(int i = 0; i < 5 ; i++){
        for (int j = 0; j < 5; j++){
            if ( i == j && numbers[i][j] == 0){
                mcount++;
            }
            if ( i + j == 4 && numbers [i][j] == 0){
                acount++;
            }
        }

    }
    if (mcount == 5){
        diagonal++;
    }
    if (acount == 5){
        diagonal++;
    }
    return diagonal;
}


// void check_duplicate_pick(int picked_number[75]){
//     int check;
//     int count = 0;
//     int checking[75];

//     for(int i = 0 ; i < 75 ; i++){
//         check = pick_number(&count, picked_number);
//         checking[i] = check;
//         printf("%d ", check);
//         for(int j = 0 ; j < i ; j++){
//             if(check == checking[j]){
//                 printf("The number is duplicate\n");
//             }
//         }
//     }
// }