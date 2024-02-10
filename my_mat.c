#include <stdio.h>
#include <stdbool.h> // For boolean
#include "my_mat.h"

// Function to initialize the matrix
void initialize_Array(int** matrix) {
    // Copy the elements from the matrix to the array
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("value : ");
            scanf(" %d", &matrix[i][j]);
        }
    }
}

// Calculates the minimum path which has not been visited!
int minDistance(int dist[], bool includes[]) {
    int min = INFINITY;  // At first equle to the highest int and then represents the lowest path
    int min_index;  // Represent the minimum index that will be returned
    for (int v = 0; v < size; v++) {
        if (includes[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function which uses dijkstra algorithm, returns the shortest path between two nodes
int dijkstra_algorithm(int** matrix, int i, int j) {
    int dist[size]; // Array to store the shortest distance from i to to all the nodes
    bool includes[size]; // Array to represent whether node i is included in this shortest path or not

    // Initialize all distances as infinite and includes[] as false
    for (int x = 0; x < size; x++) {
        dist[x] = INFINITY;
        includes[x] = false;
    }

    // Shortest distance of source node from itself is always 0
    dist[i] = 0;

    // This loop repeats as much as the amount of nodes there are
    //at the last loop you are sure that the array holds the shortest pathes becuase it has stored the minimum valuse after visiting all the nodes
    for (int count = 0; count < size - 1; count++) {
        // u = index of node with shortest path wh
        // u is the index with shortest path and which has not been visited yet
        int u = minDistance(dist, includes);

        // Mark the picked node as processed
        includes[u] = true;

        // For all nodes update if needed
        for (int v = 0; v < size; v++) {
            // Dist[v] is not in includes and it is not itself
            if (!includes[v] && matrix[u][v] != 0)   
            {
                // There is an edge from u to v and the total weight of path from i to v through u is smaller than current value of dist[v]
                if (dist[u] != INFINITY && dist[u] + matrix[u][v] < dist[v]) {   
                    dist[v] = dist[u] + matrix[u][v];    // Update shortest path
                }
            }
        }
    }
    return(dist[j]);
}

// Function to find if exists rout between a given i and j on our matrix
void is_path(int** matrix, int i, int j){

    int path = dijkstra_algorithm(matrix, i, j);  // The resulting path after using dijkstra_algorithm

    // Check if the indexes are in bounds
    if (i < 0 || i >= size || j < 0 || j >= size) {
        printf("false\n"); // Out of bounds
    }
    // Check if the value at the given indices is bigger then 0 AND smaller then infinity(indicating a route)
    else if (path < INFINITY && path != 0) {
        printf("true\n"); // Path exists
    }
    else
    {
         printf("false\n"); // No path
    }
}

void shortest_path(int** matrix, int i, int j){
    int path = dijkstra_algorithm(matrix,i,j);
    if (path < INFINITY && path != 0)
    {
        printf("%d\n", path); // Prints path
    }
    else{
        printf("-1\n"); // No path
    }
}