#include <stdio.h>
#include "data.h"

typedef struct {
  int dia, mes, ano;
} tdata;

int main(){
  int i = 0, x = 0;
  tdata data1, data2;
  scanf("%d/%d/%d", &data1.dia, &data1.mes, &data1.ano);
  scanf("%d/%d/%d", &data2.dia, &data2.mes, &data2.ano);

  if(verificaDataValida(data1.dia, data1.mes, data1.ano) && verificaDataValida(data2.dia, data2.mes, data2.ano)){
    printf("Primeira data: ");
    imprimeDataExtenso(data1.dia, data1.mes, data1.ano);
    printf("\n");
    printf("Segunda data: ");
    imprimeDataExtenso(data2.dia, data2.mes, data2.ano);
    printf("\n");
    if(comparaData(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano) < 0){
      printf("A primeira data eh mais antiga\n");
    } else if(comparaData(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano) > 0){
      printf("A segunda data eh mais antiga\n");
    } else if(comparaData(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano) == 0){
      printf("As datas sao iguais\n");
    }
    printf("A diferenca em dias entre as datas eh: %02d dias\n", calculaDiferencaDias(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano));
  } else {
    printf("A primeira e/ou segunda data(s) invalida(s)");
  }
  return 0;
}