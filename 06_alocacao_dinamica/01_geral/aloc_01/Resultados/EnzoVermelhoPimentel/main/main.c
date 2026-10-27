#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
  int i;
  int* vetor;
  float media = 0;
  scanf("%d", &i);
  vetor = CriaVetor(i);
  LeVetor(vetor, i);
   media = CalculaMedia(vetor, i);
  printf("%.2f", media);
  LiberaVetor(vetor);
  return 0;
}