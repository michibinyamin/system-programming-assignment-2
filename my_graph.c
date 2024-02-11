#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"

int main() {
    int i, j;
    char choice;
    // Allocate memory
    int **matrix = (int**) malloc(size * sizeof(int*));

    for (int i = 0; i < size; ++i){
        matrix[i] = (int*) malloc(size * sizeof(int));
    }

    do // Loop untill C is enterd by the user
    {
        //printf("type the function you want : ");
        scanf(" %c", &choice);

        switch (choice)
        {
            case 'A':
            {
                initialize_Array(matrix); //initialize the array
                break;
            }

            case 'B':
            {
                //printf("type first node : ");
                scanf("%d", &i);
                //printf("type second node : ");
                scanf("%d",&j);
                is_path(matrix, i, j);    //will be printed in the function
                break;
            }

            case 'C':
            {
                //printf("type first node : ");
                scanf("%d", &i);
                //printf("type second node : ");
                scanf("%d",&j);
                shortest_path(matrix, i, j);    //will be printed in the function
                break;
            }

            default:
                break;      //leave loop option
        }
    }
    while(choice != 'D' && choice != EOF);
    
    for (int i = 0; i < size; ++i){
        free(matrix[i]);
    }

    free(matrix);

    return 0;
    }