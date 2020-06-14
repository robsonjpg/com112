#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "com112_sort.h"
#include "com112_file.h"

int menu(int *dados, int *vetC, int *vetorD, int qtd, int *mov, int *comp, int *movC, int *compC, int *moveD, int *compaD);
void relatorio(int mov, int comp, double tmp);

//-------------------------------------------------------------------------------------------------------------------------------------------
int main(){
  int *dados, mov, comp, qtd , i, movC, compC, moveD, compaD;
  double tmp, tmpC, tmpD;
  printf("\nDigite 10000 para gerar 10mil números no vetor:\n");
  scanf("%d", &qtd);
  dados = (int *) malloc(qtd * sizeof(int));

  //printf("\n\nOS NÚMEROS GERADOS FORAM:\n", qtd);
  for(i=0; i<qtd; i++){
    dados[i] = rand() % 10000;
    //printf("%d", dados[i]);
    //printf("\n");
  }

  int *vetC;

  vetC = (int *) malloc(qtd * sizeof(int));
  //printf("NUMEROS GERADOS EM ORDEM CRESCENTE\n");
  for(int i=0; i<qtd; i++){
    vetC[i] = i;
    //printf("%d\n", vetC[i]);
  }

  int *vetorD;

  vetorD = (int *) malloc(qtd * sizeof(int));
  for(int i=0; i<qtd; i++){
    vetorD[i] = i;
  }
  for (int i = 0; i < qtd - 1; i++){
      for (int j = i; j < qtd - 1; j++){
        if (vetorD[i] < vetorD[j]){
          int temporaria = vetorD[i];
          vetorD[i] = vetorD[j];
          vetorD[j] = temporaria;
        }
      }
  }
  //printf("NUMEROS GERADOS EM ORDEM DECRESCENTE\n");
  /*for(int i=0; i<qtd; i++){
    printf("%d\n", vetorD[i]);
  }*/

  escreve_dado(dados, qtd, 0);  
  menu(dados, vetC, vetorD, qtd, &mov, &comp, &movC, &compC, &moveD, &compaD); 
  return 0;
}
//-------------------------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------------------------------------
int menu(int *dados, int *vetC, int *vetorD, int qtd, int *mov, int *comp, int *movC, int *compC, int *moveD, int *compaD){ 
  int aux;
  double tmp, tmpC, tmpD; 

  do
  {
    printf("\n\nMÉTODOS DE ORDENAÇÃO DISPONÍVEIS, SELECIONE ALGUM:\n");
    printf("\n1) Bubble Sort");
    printf("\n2) Selection Sort");
    printf("\n3) Insertion Sort");
    printf("\n4) Merge Sort");
    printf("\n5) Quick Sort");
    printf("\n6) Tirar o Relatorio");
    printf("\n7) Sair\n\n");
    scanf("%d", &aux);

    switch(aux){
      case 1:
        printf("\n\nORDENANDO POR BUBBLE SORT");
        tmp = bubble_sort(dados, qtd, mov, comp);
        tmpC = bubble_sort(vetC, qtd, movC, compC);
        tmpD = bubble_sort(vetorD, qtd, moveD, compaD);
        escreve_dado(dados, qtd, 1);
        printf("\n\nORDEM ALEATÓRIA\n");
        relatorio(*mov, *comp, tmp);
        printf("\n\nORDEM CRESCENTE\n");
        relatorio(*movC, *compC, tmpC);
        printf("\n\nORDEM DECRESCENTE\n");
        relatorio(*moveD, *compaD, tmpD);
        printf("\n\nORDENADOS COM SUCESSO\n\n");
      break;

      case 2:
        printf("\n\nORDENANDO POR SELECTION SORT");
        printf("\n\nORDEM ALEATÓRIA\n");
        tmp = selection_sort(dados, qtd, mov, comp);
        relatorio(*mov, *comp, tmp);
        escreve_dado(dados, qtd, 1);
        printf("\n\nORDEM CRESCENTE\n");
        tmpC = selection_sort(vetC, qtd, movC, compC);
        relatorio(*movC, *compC, tmpC);
        printf("\n\nORDEM DECRESCENTE\n");
        tmpD = selection_sort(vetorD, qtd, moveD, compaD);
        relatorio(*moveD, *compaD, tmpD); 
        printf("\n\nORDENADOS COM SUCESSO\n\n");
      break;

      case 3:
        printf("\n\nORDENANDO POR INSERTION SORT"); //SEMPRE TESTE ESSE PRIMEIRO PARA SAIR O RESULTADO CERTO
        tmp = insertion_sort(dados, qtd, mov, comp);
        tmpC = insertion_sort(vetC, qtd, movC, compC);
        tmpD = insertion_sort(vetorD, qtd, moveD, compaD);
        escreve_dado(dados, qtd, 1);
        printf("\n\nORDEM ALEATÓRIA\n");
        relatorio(*mov, *comp, tmp);
        printf("\n\nORDEM CRESCENTE\n");
        relatorio(*movC, *compC, tmpC);
        printf("\n\nORDEM DECRESCENTE\n");
        relatorio(*moveD, *compaD, tmpD);
        printf("\n\nORDENADOS COM SUCESSO\n\n");
      break;

      case 4:
        printf("\n\nORDENANDO POR MERGE SORT");
        *mov = 0; *comp = 0;
        tmp = merge_sort(dados, qtd, 0, qtd-1, mov, comp);
        tmpC = merge_sort(vetC, qtd, 0, qtd-1, movC, compC);
        tmpD = merge_sort(vetorD, qtd, 0, qtd-1, moveD, compaD);
        escreve_dado(dados, qtd, 1);
        printf("\n\nORDEM ALEATÓRIA\n");
        relatorio(*mov, *comp, tmp);
        printf("\n\nORDEM CRESCENTE\n");
        relatorio(*movC, *compC, tmpC);
        printf("\n\nORDEM DECRESCENTE\n");
        relatorio(*moveD, *compaD, tmpD);
        printf("\n\nORDENADOS COM SUCESSO\n\n");
      break;

      case 5:
        printf("\n\nORDENANDO POR QUICK SORT");
        *mov = 0; *comp = 0;
        tmp = quick_sort(dados, 0, qtd-1, mov, comp);
        tmpC = quick_sort(vetC, 0, qtd-1, movC, compC);
        tmpD = quick_sort(vetorD, 0, qtd-1, moveD, compaD);
        escreve_dado(dados, qtd, 1);
        printf("\n\nORDEM ALEATÓRIA\n");
        relatorio(*mov, *comp, tmp);
        printf("\n\nORDEM CRESCENTE\n");
        relatorio(*movC, *compC, tmpC);
        printf("\n\nORDEM DECRESCENTE\n");
        relatorio(*moveD, *compaD, tmpD);
        printf("\n\nORDENADOS COM SUCESSO\n\n");
      break;

      case 6:
        printf("\n\nGERANDO RELATÓRIO\n");
        escreve_relatorio(dados, vetC, qtd, mov, comp);
        escreve_dado(dados, qtd, 1);
        printf("\nSUCESSO AO GERAR ^^\n");
      break;

      case 7:
        printf("\nFINALIZANDO O PROGRAMA :'(");
      exit(0);
    }
  }while(aux!=7);
  return 1;
}
//-------------------------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------------------------------------
void relatorio(int mov, int comp, double tmp){  
  printf("\nRELATÓRIO\n");
  printf("\nTEMPO DE EXECUÇÃO: %f", tmp);
  printf("\nNÚMERO DE COMPARAÇÕES FEITAS DENTRO DO VETOR: %d", comp);
  printf("\nNÚMERO DE MOVIMENTAÇÕES FEITAS DENTRO DO VETOR: %d", mov);
  return;
}
//-------------------------------------------------------------------------------------------------------------------------------------------
