#include <bits/stdc++.h>
using namespace std;
#define N 4

void rotateMatrix(int mat[][N])
{
    for (int x = 0; x < N / 2; x++)
    {
        for (int y = x; y < N - x - 1; y++)
        {
            int temp = mat[x][y];
            mat[x][y] = mat[N - 1 - y][x];
            mat[N - 1 - y][x] = mat[N - 1 - x][N - 1 - y];
            mat[N - 1 - x][N - 1 - y] = mat[y][N - 1 - x];
            mat[y][N - 1 - x] = temp;
        }
    }
}

void displayMatrix(int mat[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", mat[i][j]);

        printf("\n");
    }
    printf("\n");
}

int main()
{
    int mat[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    // Tese Case 2
    /* int mat[N][N] = { 
                        {1, 2, 3}, 
                        {4, 5, 6}, 
                        {7, 8, 9} 
                    }; 
     */

    // Tese Case 3
    /*int mat[N][N] = { 
                    {1, 2}, 
                    {4, 5} 
                };*/

    // displayMatrix(mat);

    rotateMatrix(mat);

    // Print rotated matrix
    displayMatrix(mat);

    return 0;
}