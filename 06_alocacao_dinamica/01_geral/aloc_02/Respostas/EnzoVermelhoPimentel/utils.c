#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * Função que cria uma matriz de inteiros, alocada dinamicamente. Se a alocação falhar, o programa é encerrado.
 * 
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz. 
 * @return Ponteiro para a matriz alocada.
*/
int **CriaMatriz(int linhas, int colunas){
  int i = 0;
  int **matriz =  malloc(linhas * sizeof(int *));
  if(matriz == NULL){
    printf("erro");
    exit(1);
  } else {
    for(i = 0; i < linhas; i++){
      matriz[i] = malloc(colunas * sizeof(int));
      if(matriz[i] == NULL){
        for(int j = 0; j < i; j++){
          free(matriz[j]);

          free(matriz);
          exit(1);
        }
      }
    }
  }
  return matriz;
}

/**
 * Função que libera a memória alocada para uma matriz de inteiros.
 * 
 * @param matriz Ponteiro para a matriz a ser liberada.
 * @param linhas Número de linhas da matriz.
*/
void LiberaMatriz(int **matriz, int linhas){
  int i = 0;
  for(i = 0; i < linhas; i++){
    free(matriz[i]);
  }
  free(matriz);
}

/**
 * Função que lê uma matriz de inteiros da entrada padrão.
 * 
 * @param matriz Ponteiro para a matriz a ser lida.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
*/
void LeMatriz(int **matriz, int linhas, int colunas){
  int i, z;
  for(i = 0; i < linhas; i++){
    for(z = 0; z < colunas; z++){
      scanf("%d", &matriz[i][z]);
    }
  }
}

/**
 * Imprime a matriz transposta da matriz dada.
 * 
 * @param matriz Ponteiro para a matriz.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
*/
void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas){
  int i, z;
  for(i = 0; i < colunas; i++){
    for(z = 0; z < linhas; z++){
      printf("%d ", matriz[z][i]);
    }
    printf("\n");
  }
}