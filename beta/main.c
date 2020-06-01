#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "com112_sort.h"
#include "com112_file.h"

//*dados -> vetor de numeros principal
//qtd -> quantidade de numeros solicitada pelo usuario
//*mov -> quantidade de movimentacoes realizadas no Sort
//*comp -> quantidade de comparacoes realizadas no Sort
//i -> auxiliar para movimentacao nos vetores
//tmp -> salva tempo de execucao das funcoes de Sort
//aux -> utilizada para selecao no menu

int menu(int *dados, int qtd, int *mov, int *comp);
void relatorio(int mov, int comp, double tmp);


int main(){
  int *dados, mov, comp, qtd , i;
  double tmp;
  printf("\nDigite a quantidade de numeros que deseja ordenar:");
  scanf("%d", &qtd);
  dados = (int *) malloc(qtd * sizeof(int));

  //gerar numeros aleatorios (de 0 a 10000) e armazena no vetor *dados
  printf("\n\nGerando %d numeros aleatorios...\n", qtd);
  for (i=0; i<qtd; i++){
    dados[i] = rand() % 10000;
  }
  printf("\nNumeros aleatorios gerados no arquivo com112_entrada.txt\n");

  escreve_dado(dados, qtd, 0);    //escreve dados de entrada no txt - passa o valor 0 que representa "com112_entrada.txt"
  menu(dados, qtd, &mov, &comp);  //chama funcao para exibicao do menu
  return 0;
}



int menu(int *dados, int qtd, int *mov, int *comp){     //menu de opções
  int aux;
  double tmp;

  do
  {
    printf("\n\n\n__________________________________________________________________\n");
    printf("\n_______________________Metodos de Ordenacao_______________________\n");
    printf("\n1. Bubble Sort");
    printf("\n2. Selection Sort");
    printf("\n3. Insertion Sort");
    printf("\n4. Merge Sort");
    printf("\n5. Relatorio de Comparacao");
    printf("\n\n_________________________Retorno de Dados_________________________\n");
    printf("\n6. Verificar com112_entrada.txt \t(Numeros aleatorios gerados)");
    printf("\n7. Verificar com112_saida.txt   \t(Numeros após ordenação)");
    printf("\n__________________________________________________________________\n");
    printf("\n8. Nova sequencia aleatoria");
    printf("\n9. Sair do programa");
    printf("\n__________________________________________________________________\n");
    printf("\nSelecione uma das opcoes:");
    scanf("%d", &aux);

    switch(aux){
      case 1:
        printf("\nMetodo Bubble Sort selecionado!!!");
        printf("\n---------------------------------------------------------------\n\n\n");
        tmp = bubble_sort(dados, qtd, mov, comp);
        escreve_dado(dados, qtd, 1);    //escreve dados de saida no txt - passa o valor 1 que representa "com112_saida.txt"
        relatorio(*mov, *comp, tmp);
        printf("\n\nNumeros ordenados salvos com sucesso no arquivo com112_saida.txt\n\n");
      break;

      case 2:
        printf("\nMetodo Selection Sort selecionado!!!");
        printf("\n---------------------------------------------------------------\n\n\n");
        tmp = selection_sort(dados, qtd, mov, comp);
        escreve_dado(dados, qtd, 1);    //escreve dados de saida no txt - passa o valor 1 que representa "com112_saida.txt"
        relatorio(*mov, *comp, tmp);
        printf("\n\nNumeros ordenados salvos com sucesso no arquivo com112_saida.txt\n\n");
      break;

      case 3:
        printf("\nMetodo Insertion Sort selecionado!!!");
        printf("\n---------------------------------------------------------------\n\n\n");
        tmp = insertion_sort(dados, qtd, mov, comp);
        escreve_dado(dados, qtd, 1);    //escreve dados de saida no txt - passa o valor 1 que representa "com112_saida.txt"
        relatorio(*mov, *comp, tmp);
        printf("\n\nNumeros ordenados salvos com sucesso no arquivo com112_saida.txt\n\n");
      break;

      case 4:
        printf("\nMetodo Merge Sort selecionado!!!");
        printf("\n---------------------------------------------------------------\n\n\n");
        *mov = 0; *comp = 0;
        tmp = merge_sort(dados, qtd, 0, qtd-1, mov, comp);
        escreve_dado(dados, qtd, 1);    //escreve dados de saida no txt - passa o valor 1 que representa "com112_saida.txt"
        relatorio(*mov, *comp, tmp);
        printf("\n\nNumeros ordenados salvos com sucesso no arquivo com112_saida.txt\n\n");
      break;

      case 5:
        printf("\nRelatorio de compacarao solicitado!!!\n");
        escreve_relatorio(dados, qtd, mov, comp);
        escreve_dado(dados, qtd, 1);
        printf("\nRelatorio de compacarao salvo no arquivo com112_relatorio.txt!!!\n");
      break;

      case 6:
        printf("\n\n\n---------------------------------------------------------------");
        printf("\nSequencia de numeros aleatorios gerados solicitada!!!\n\n");
        le_dado(0);   //0 representa com112_entrada.txt
        printf("\n---------------------------------------------------------------\n\n\n");
      break;

      case 7:
        printf("\n\n\n---------------------------------------------------------------");
        printf("\nSequencia de numeros ordenados solicitada!!!\n\n");
        le_dado(1);   //1 representa com112_saida.txt
        printf("\n---------------------------------------------------------------\n\n\n");
      break;

      case 8:
        printf("\nRequição de novos numeros aleatórios realizada!!!");
        return main();

      case 9:
        printf("\nSaindo do programa...!!!");
      exit(0);
    }
  }while(aux!=9);
  return 1;
}


void relatorio(int mov, int comp, double tmp){      //imprime o relatorio individual do sort requisitado
  printf("\n\n\n---------------------------------------------------------------");
  printf("\nRelatorio de Operacao\n");
  printf("\nTempo de execução: %f", tmp);
  printf("\nNúmero de comparações entre elementos do vetor: %d", comp);
  printf("\nNúmero de movimentações entre elementos do vetor: %d", mov);
  if(mov == 0){
    printf("\nNumeros ja ordenados, gere uma nova sequencia aleatoria");
  }
  printf("\n---------------------------------------------------------------\n\n\n");
  return;
}
