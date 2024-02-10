#include <stdio.h>
#include <stdlib.h> // For malloc and free

#define max_size 5
#define max_weight 20

int max(int a, int b){  //returns the maximum between two integers
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
    
}

//  This function calculates and returns the list of which items to use
int* Items_in_bag(int **matrix, int values[], int selected_bool[]){

    int Current_val = matrix[max_size][max_weight];
    
    for (int y = max_size; y > 0; y--)  
    {
        int b = 0;
        for (int i = 0; i < max_weight + 1; i++)
        {
            if (matrix[y-1][i] == Current_val)
            {
                b = 1;  //true meaning that there is the same weight in the row above
                break;
            }
        }

        if (b)  // if there is
        {
            selected_bool[y-1] = 0;  // y-1 in the list = y in the matrix
        }
        else
        {
            selected_bool[y-1] = 1;  // Add true to list
            Current_val = Current_val - values[y-1];  // Update the value
        }
    }
    return selected_bool;
}

//uses dynamic programing and puts all values in a matrix
int* make_matrix(int w[], int v[], int selected_bool[]){

    //initialize the array boundries
    int **matrix = (int**) malloc((max_size+1) * sizeof(int*));

    for (int i = 0; i < max_size+1; ++i){
        matrix[i] = (int*) malloc((max_weight+1) * sizeof(int));
    }

    // Matrix building accourding to dynamic programing
    for (int i = 0; i < max_size+1; i++)
    {
        for (int j = 0; j < max_weight+1; j++)
        {
            if (i==0 || j==0)   // if i or j are 0 then initialize 0
            {
                matrix[i][j] = 0;
            }
            else if (j < w[i-1])     // condition to check if the current item fits with the current weight
            {
                matrix[i][j] = matrix[i-1][j];
            }
            else
            {
                matrix[i][j] = max(matrix[i-1][j], (matrix[i-1][j - w[i-1]]) + v[i-1]);     //notice that the lists dont include item 0 in the metrix so we will teke i-1
            }
        }  
    }

    int *new_selected_bool = Items_in_bag(matrix, v , selected_bool);

    // Free allocated memory for the matrix
    for (int i = 0; i < max_size + 1; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    return new_selected_bool;
}

int KnapSack(int weights[], int values[], int selected_bool[]){

    int max_value = 0;
    for (int i = 0; i < max_size; i++)
    {
        if (selected_bool[i])
        {
            max_value = max_value + values[i];
        }
    }
    return max_value;
}

int main(){
    int values[max_size];
    int weights[max_size];
    int selected_bool[max_size];
    char result[max_size]; 

    for (int i = 0; i < max_size; i++) {
        printf("Type value of item %c : ", 'A' + i);
        scanf("%d", &values[i]); // Insert value to list

        printf("Type weight of item %c : ", 'A' + i);
        scanf("%d", &weights[i]); // Insert weight to list
    }

    int *new_selected_bool = make_matrix(weights, values, selected_bool);  // Stores the selected bool which determins which items to take
    int max_profit = KnapSack(weights, values, new_selected_bool);  // Stores the maximum profit with the given items(checks with the new selected bool)

    // Add the items to the result list
    int x = 0;
    for (int i = 0; i < max_size; i++)
    {
        if (new_selected_bool[i])   // When true add the item
        {
            result[x] = 'A' + i;     // i + 65 = {A,B,C,D,....}
            x++;
        } 
    }

    // Print
    printf("Maximum profit: %d\n", max_profit);
    printf("Items that give the maximum profit: [");

    for (int j = 0; j < x; j++) {
        printf("%c%s", result[j], (j < x - 1) ? ", " : "");
    }
    printf("]\n");
    return 0;
}