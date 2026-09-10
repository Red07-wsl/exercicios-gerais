#include <stdio.h>
#include "matrix_utils.h"

void matrix_read(int rows, int cols, int matrix[rows][cols]){
    int i, z;
    for(i = 0; i < rows; i++){
        for(z = 0; z < cols; z++){
            scanf("%d", &matrix[i][z]);
        }
    }
}

void matrix_print(int rows, int cols, int matrix[rows][cols]){
    int i, z;
    for(i = 0; i < rows; i++){
        printf("|");
        for(z = 0; z < cols; z++){
            printf("%d", matrix[i][z]);
            if(z != cols-1){
            printf(" ");
            }
        }
        printf("|");
        printf("\n");
    }
    printf("\n");
}

int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2){
    if(rows1 == rows2){
        if(cols1 == cols2){
            return 1;
        }
    } 
    return 0;
}

int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2){
    if(rows1 == rows2){
        if(cols1 == cols2){
            return 1;
        }
    } 
    return 0;
}

int possible_matrix_multiply(int cols1, int rows2){
    if(cols1 == rows2){
        return 1;
    }
    return 0;
}

void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]){
    int i, z;

    for(i = 0; i < rows1; i++){
        for(z = 0; z < cols1; z++){
            result[i][z] = matrix1[i][z] + matrix2[i][z];
        }
    }
}

void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]){
    int i, z;

    for(i = 0; i < rows1; i++){
        for(z = 0; z < cols1; z++){
            result[i][z] = matrix1[i][z] - matrix2[i][z];
        }
    }
}

void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]){
    int i, z, p;
    for(i = 0; i < rows1; i++){
        for(z = 0; z < cols2; z++){
            result[i][z] = 0;
            for(p = 0; p < cols1; p++){
            result[i][z] += matrix1[i][p] * matrix2[p][z];
            }
        }
    }
}

void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]){
    int i, z;
    for(i = 0;i < rows; i++){
        for(z = 0; z < cols; z++){
            result[z][i] = matrix[i][z];
        }
    }
}

void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar){
    int i, z;
    for(i = 0; i < rows; i++){
        for(z = 0; z < cols; z++){
            matrix[i][z] = matrix[i][z] * scalar;
        }
    }
}

