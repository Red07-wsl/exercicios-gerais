#include <stdio.h>
#include "matrix_utils.h"

int main(){
  int i, z, l1, c1, l2, c2, x, end = 0, escalar, qualmatrixmult;
  scanf("%d %d", &l1, &c1);
  int matrix1[l1][c1];
  matrix_read(l1, c1, matrix1);
  scanf("%d %d", &l2, &c2);
  int matrix2[l2][c2];
  matrix_read(l2, c2, matrix2);
  int result1[l2][c2];
  int result2[l1][c2];
  int result51[c1][l1];
  int result52[c2][l2];

  while(!end){
    printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\n");
    printf("Opcao escolhida: ");
    scanf("%d", &x);
    printf("\n");

    if(x == 1){
      if(possible_matrix_sum(l1, c1, l2, c2)){
        matrix_add(l1,c1,matrix1,l2,c2,matrix2,result1);
        matrix_print(l2,c2,result1);
      } else {
        printf("Erro: as dimensoes da matriz nao correspondem\n");
        printf("\n");
      }
    }
    if(x == 2){
      if(possible_matrix_sub(l1,c1,l2,c2)){
        matrix_sub(l1,c1,matrix1,l2,c2,matrix2,result1);
        matrix_print(l2,c2,result1);
    } else {
      printf("Erro: as dimensoes da matriz nao correspondem\n");
      printf("\n");
    }
  }
    if(x == 3){
      if(possible_matrix_multiply(l2,c1)){
        matrix_multiply(l1,c1,matrix1,l2,c2,matrix2,result2);
        matrix_print(l1,c2,result2);
      } else {
        printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
        printf("\n");
      }
    }
    if(x == 4){
      scanf("%d", &escalar);
      scanf("%d", &qualmatrixmult);
      if(qualmatrixmult == 1){
        scalar_multiply(l1,c1,matrix1,escalar);
        matrix_print(l1,c1,matrix1);
      }
      if(qualmatrixmult == 2){
        scalar_multiply(l2,c2,matrix2,escalar);
        matrix_print(l2,c2,matrix2);
      }
    }
    if(x == 5){
      transpose_matrix(l1,c1,matrix1,result51);
      matrix_print(c1,l1,result51);
      transpose_matrix(l2,c2,matrix2,result52);
      matrix_print(c2,l2,result52);
    }
    if(x == 6){
      end = 1;
    }
  }
  return 0;
}