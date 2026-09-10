#include <stdio.h>
#include "data.h"

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @return int Retorna 1 se a data é válida e 0 caso contrário.
 */
int verificaDataValida(int dia, int mes, int ano){
    if(mes > 12|| mes < 1){
        return 0;
    }
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        if(dia > 31 || dia < 0){
            return 0;
        }
    }
    if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        if(dia > 30 || dia < 0){
            return 0;
        }
    }
    if(mes == 2){
        if(verificaBissexto(ano)){
            if(dia > 29 || dia < 0){
                return 0;
            }
        } else {
            if (dia > 28 || dia < 0){
                return 0;
            }
        }
    }
    return 1;
}

/**
 * @brief Imprime o nome do mês por extenso.
 * 
 * @param mes Mês a ser impresso.
 */
void imprimeMesExtenso(int mes){
    switch(mes){
        case 1:
            printf("Janeiro");
            break;
        case 2:
            printf("Fevereiro");
            break;
        case 3:
            printf("Marco");
            break;
        case 4:
            printf("Abril");
            break;
        case 5:
            printf("Maio");
            break;
        case 6:
            printf("Junho");
            break;
        case 7:
            printf("Julho");
            break;
        case 8:
            printf("Agosto");
            break;
        case 9:
            printf("Setembro");
            break;
        case 10:
            printf("Outubro");
            break;
        case 11:
            printf("Novembro");
            break;
        case 12:
            printf("Dezembro");
            break;
    }
}

/**
 * @brief Imprime a data por extenso.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%02d ", dia);
    printf("de ");
    imprimeMesExtenso(mes);
    printf(" de ");
    printf("%d", ano);


}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param ano Ano a ser verificado.
 * @return int Retorna 1 se o ano é bissexto e 0 caso contrário.
 */
int verificaBissexto(int ano){
    if(ano % 400 == 0){
        return 1;
    }
    if(ano % 100 == 0){
        return 0;
    }
    if(ano % 4 == 0){
        return 1;
    }
    return 0;
    
}

/**
 * @brief Calcula o número de dias de um mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias do mês.
 */
int numeroDiasMes(int mes, int ano){
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        return 31;
        }
    if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        return 30;
        }
    if(mes == 2){
        if(verificaBissexto(ano)){
            return 29;
        } else {
            return 28;
        }
    }
}

/**
 * @brief Compara duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna 1 se a primeira data é maior que a segunda, -1 se a primeira data é menor que a segunda
 * e 0 se as datas são iguais.
 * A data ser "maior" significa que ela está mais no futuro.
 */
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if(ano1 > ano2){
        return 1;
    }
    if(ano1 == ano2){
        if(mes1 > mes2){
            return 1;
        }
        if(mes1 < mes2){
            return -1;
        }
        if(mes1 == mes2){
            if ( dia1 > dia2){
                return 1;
            }
            if(dia1 == dia2){
                return 0;
            }
            if(dia1 < dia2){
                return -1;
            }
        }
    }
    if(ano1 < ano2){
        return -1;
    }
}


/**
 * @brief Calcula o número de dias até o mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias até o mês.
*/
int calculaDiasAteMes(int mes, int ano) {
    int dias = 0, i;

    for (i = 1; i < mes; i++) {
        if (i == 2) {
            if (verificaBissexto(ano))
                dias += 29;
            else
                dias += 28;
        }
        else if (i == 4 || i == 6 || i == 9 || i == 11) {
            dias += 30;
        }
        else {
            dias += 31;
        }
    }

    return dias;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna o número de dias de diferença entre as datas.
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    int i, z, diferenca = 0, data1, data2, difano;
    data1 = calculaDiasAteMes( mes1, ano1) + dia1;
    data2 = calculaDiasAteMes( mes2, ano2) + dia2;
    if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) > 0){
         if(  ano1 > ano2 && mes1 > mes2 || ano1 > ano2 && mes1 == mes2 && dia1 > dia2){
            difano = ano1- ano2;
            for(i = 0; i < difano; i++){
                if(verificaBissexto(ano2 + i)){
                    diferenca += 366;
                } else {
                    diferenca +=365;
                }
            }
         }
         diferenca += data1 - data2;
         return diferenca;
    }
    if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) < 0){
         if(  ano2 > ano1 && mes2 > mes1 || ano2 > ano1 && mes2 == mes1 && dia2 > dia1){
            difano = ano2 - ano1;
            for(i = 0; i < difano; i++){
                if(verificaBissexto(ano1 + i)){
                    diferenca += 366;
                } else {
                    diferenca +=365;
                }
            }
         }
         diferenca += data2 - data1;
         return diferenca;
    }
     if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 0){
        return 0;
        }
}
