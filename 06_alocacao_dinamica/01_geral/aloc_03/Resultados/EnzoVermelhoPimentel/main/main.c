#include "utils_char.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
  int tamanho = 0;
  char *vetor;
  scanf("%d", &tamanho);
  while(getchar() != '\n');
  
  vetor = CriaVetor(tamanho);
  ImprimeString(vetor, tamanho);
  LeVetor(vetor, tamanho);
  ImprimeString(vetor, tamanho);
  LiberaVetor(vetor);

  return 0;
}