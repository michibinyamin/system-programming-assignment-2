#ifndef _MY_MAT_H
#define _MY_MAT_H

#define size 10
#define INFINITY 2147483647

/*
 * initialize the matrix with user input
*/
void initialize_Array(int** matrix);

/*
 * returns if there is a path from i to j
*/
void is_path(int** matrix, int i, int j);

/*
 * Return the shortest path from i to j
*/
void shortest_path(int** matrix, int i, int j);

#endif