#include <stdio.h>
#include "matrix_utils.h"

int main(){
  int i, z, l1, c1, l2, c2, x;
  scanf("%d %d", &l1, &c1);
  int matrix1[l1][c1];
  matrix_read(l1, c1, matrix1);
  scanf("%d %d", &l2, c2);
  int matrix2[l2][c2];
  matrix_read(l2, c2, matrix2);

  printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz pro escalar\n5 - Transposta\n6 - Encerrar o programa\n");
  printf("Opcao escolhida:");
  scanf("%d", &x);
}