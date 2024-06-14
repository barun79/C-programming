#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "DrawTool.h"
#include "ListLib.h"
#include "FileLib.h"

int main(int argc, char* argv[]){
    char Map[MAXMAPSIZE][MAXMAPSIZE] = {};
    char LineType;
    int x;
    int y;
    int MyMapSize = 20;
    int count;
    char mark;
    char DC[100];
    char user_input[4];
    char* token;

    NODE* LinkedListHead = NULL;

    
    FILE *fptr = OpenFile(argc, argv);

    InitializeMap(Map);
    PrintMap(Map);
    ReadFileIntoLinkedList(fptr, &LinkedListHead); 

    do{
        printf("Please enter 1-3 letters ");
        scanf("%s", user_input);
        if(strlen(user_input) < 0 || strlen(user_input) > 3){
            printf("Invalid input. Please enter 1-3 letters.\n");
        }
    } while(strlen(user_input) < 0 || strlen(user_input) > 3);

    for(int i = 0; i < strlen(user_input); i++){
        user_input[i] = toupper(user_input[i]); 
        NODE* Temp = LinkedListHead;
        
        do{
            Temp = FindLetter(Temp, user_input[i],DC);
            printf("%s ", DC);
            token = strtok(DC, "(),");
            if(DC[0] =='\0'){
                continue;
            }
            if(token != NULL){
                LineType = token[0];
            }else{
                printf("Invalid command prompt.\n");
                continue;
            }
            token = strtok(NULL, "(),");
            if(token !=NULL){
                x = atoi (token);
            }else{
                printf("Invalid command prompt.\n");
                continue;
            }
            token = strtok(NULL, "(),");
            if (token != NULL){
                y =  (7 * i) + atoi(token);
            }else{
                printf("Invalid command prompt.\n");
                continue; 
            }
            token = strtok(NULL, "(),");
            if (token != NULL){
                count = atoi(token);
            }else{
                printf("Invalid command prompt.\n");
                continue; 
            }
            token = strtok(NULL,"(),");
            if (token != NULL){
                mark = *token;
            } else{
                mark = 'X';
            }
            
            // Check the starting point in inside the grid.
            if ( x > MyMapSize - 1 || y > MyMapSize -1){
                    printf("Coordinates out of range are not allowed.\n");
                    continue;
                }

                switch(LineType){
                    case 'V':
                        if(x + count > MyMapSize){
                            printf("Lines drawn last the borders are not allowed.\n");
                            continue;
                        }else{
                            DrawLine(Map,x,y,LineType,count,mark);
                            PrintMap(Map);
                        }
                        break;
                    case 'H':
                        if(y + count > MyMapSize){
                            printf("Lines drawn past the borders are not allowed.\n");
                            continue;
                        }else{
                            DrawLine(Map,x,y,LineType,count,mark);
                            PrintMap(Map);
                        }
                        break;
                    case 'P':
                        Map[x][y] = mark;
                        PrintMap(Map);
                        break;
                }

        }while(Temp != NULL);
    }
            
    fclose(fptr);
return 0;
}
