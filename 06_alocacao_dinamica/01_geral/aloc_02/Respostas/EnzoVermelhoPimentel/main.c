#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
  int i = 0, z = 0, linhas = 0, colunas = 0;
  int **matriz;
  scanf("%d %d", &linhas, &colunas);
  matriz = CriaMatriz(linhas, colunas);
  LeMatriz(matriz, linhas, colunas);
  ImprimeMatrizTransposta(matriz, linhas, colunas);
  LiberaMatriz(matriz, linhas);
}