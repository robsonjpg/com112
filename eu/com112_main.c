#include <stdlib.h>
#include <stdio.h>
#include "com112_sort.h"
#include <time.h>
#include "com112_file.h"



int main(void)
{





}

//Função para imprimir
int relatorio(double tempo, int n_compara, int n_movimento, int *V2, int n){
    printf("\n1. Tempo de execucao: %lf\n", tempo);
    printf("2. Numero de comparacoes: %d\n", n_compara);
    printf("3. Numero de movimentacoes entre elementos do vetor: %d\n\n", n_movimento);
    for(int i = 0; i < n; i++){
        printf("%d ", V2[i]);
    }
    printf("\n\n");

    return 1;
}