#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<ctype.h>
#include "DrawTool.h"

int main(){
    char Map[MAXMAPSIZE][MAXMAPSIZE] = {};
    int MyMapSize;
    char LineType;
    int x;
    int y;
    int count;
    char mark;
    char str[100];
    char* token;

    InitializeMap(Map, &MyMapSize);
    PrintInstructions();
    PrintMap(Map, MyMapSize);
    do{
        printf("Enter draw command (enter Q to quit) ");
        scanf("%s", str);
        token = strtok(str, "(),");
        if(token != NULL){
            LineType = toupper(*token);
        }else{
            printf("Invalid command prompt.\n");
            continue;
        }

        if (LineType != 'Q'){
            token = strtok(NULL, "(),");
            if(token !=NULL){
                x = atoi (token);
            }else{
                printf("Invalid command prompt.\n");
                continue;
            }
            token = strtok(NULL, "(),");
            if (token != NULL){
                y = atoi(token);
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
                    if(y + count > MyMapSize){
                        printf("Lines drawn last the borders are not allowed.\n");
                        continue;
                    }else{
                        DrawLine(Map,x,y,LineType,count,mark);
                        PrintMap(Map, MyMapSize);
                    }
                    break;
                case 'H':
                    if(x + count > MyMapSize){
                        printf("Lines drawn past the borders are not allowed.\n");
                        continue;
                    }else{
                        DrawLine(Map,x,y,LineType,count,mark);
                        PrintMap(Map, MyMapSize);
                    }
                    break;
                case 'P':
                    Map[x][y] = mark;
                    PrintMap(Map, MyMapSize);
                    break;
            }


        }
    } while(LineType != 'Q');

    return 0;
}
