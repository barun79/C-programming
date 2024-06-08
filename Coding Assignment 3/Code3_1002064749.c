#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_numbers (int numbers[5][5]);
void print_numbers(int numbers[5][5]);
int pick_number(int *count, int picked_number[75]);
// void check_duplicate_pick(int picked_number[75]);

int main(){
    int numbers [5][5];
    int picked_number[75];
    int count = 0;
    srand(time(0));
    fill_numbers(numbers);
    print_numbers(numbers);
    check_duplicate_pick(picked_number);

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