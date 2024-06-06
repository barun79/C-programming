#include<stdio.h>

int main(){
    int is, ie, js, je, ks, ke; 
    printf("Enter i's starting value: ");
    scanf("%d",&is);
    printf("Enter i's ending value: ");
    scanf("%d",&ie);
    printf("Enter j's starting value: ");
    scanf("%d",&js);
    printf("Enter j's ending value: ");
    scanf("%d",&je);
    printf("Enter k's starting value: ");
    scanf("%d",&ks);
    printf("Enter k's ending value: ");
    scanf("%d",&ke);

    for(int i =is; i < ie ; i++){
        for(int j = js ; j < je; j++){
            for(int k = ks; k < ke; k++){
                printf("*");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}