#include <stdlib.h>
#include <stdio.h>
#include "com112_sort.h"
#include <time.h>
#include "com112_file.h"


/////////////////////////////////////////////////////////
void bubblesort(int *v, int *compara, int *movimenta, int n){
    int aux;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1-i; j++){
            if(v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                *movimenta++;
            }
            *compara++;
        }
    }
}

/////////////////////////////////////////////////////////
void selectionsort(int *v, int *compara, int *movimenta, int n){
int i, j, aux, menor;

for(i = 0; i < n; i++){
        menor = i;
        for(j = i+1; j < n; j++)
        {   
            if(v[j] < v[menor])
                menor = j;
                *compara++;
        }
            if(i != menor){
                aux = v[i];
                v[i] = v[menor];
                v[menor] = aux;
                *movimenta++;
        }
    }
}

/////////////////////////////////////////////////////////
void insertionsort(int *v, int *compara, int *movimenta, int n){

	int i, j;
	int aux;

	for (i = 1; i < n; i++) {
		aux = v[i];
        for(j = i; (j>0) && (aux <v[j-1]); j--){
            v[j]=v[j-1];
            *compara++;
        }
        v[j]=aux;
        *movimenta++;
	}
} 

/////////////////////////////////////////////////////////

void mergesort(int *v, int n, int *compara, int *movimenta) {
    int *c = malloc(sizeof(int) * n);
    sort(v, c, 0, n - 1, compara, movimenta);
    free(c);
}

/*
Dado um vetor de inteiros v e dois inteiros i e f, ordena o vetor v[i..f] em ordem crescente.
O vetor c é utilizado internamente durante a ordenação.
*/
void sort(int *v, int *c, int i, int f, int *compara, int *movimenta) {
    if (i >= f) return;
    int m = (i + f) / 2;

    sort(v, c, i, m, compara, movimenta);
    sort(v, c, m + 1, f, compara, movimenta);
  /* Se v[m] <= v[m + 1], então v[i..f] já está ordenado. */
    if (v[m] <= v[m + 1]){
        *movimenta++;
        return;
    }
    merge(v, c, i, m, f, compara, movimenta);
}

/*
Dado um vetor v e três inteiros i, m e f, sendo v[i..m] e v[m+1..f] vetores ordenados,
coloca os elementos destes vetores, em ordem crescente, no vetor em v[i..f].
*/
void merge(int *v, int *c, int i, int m, int f, int *compara, int *movimenta) {
    int z,
    iv = i, ic = m + 1;

    for (z = i; z <= f; z++) c[z] = v[z];

    z = i;

    while (iv <= m && ic <= f) {
        *compara++;
    /* Invariante: v[i..z] possui os valores de v[iv..m] e v[ic..f] em ordem crescente. */

    if (c[iv] < c[ic]){
        v[z++] = c[iv++];
        *movimenta++;
    }
    else /* if (c[iv] > c[ic]) */ v[z++] = c[ic++];
    }

    while (iv <= m){
        v[z++] = c[iv++];
    }
    while(ic <= f){
        v[z++] = c[ic++];
    } 
    *movimenta++;
}

/////////////////////////////////////////////////////////

void menu(){
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int v[n], d1[n], d2[n], d3[n], d4[n], V2[n];

    double tempo = 0;

    //preenchendo o vetor de entrada com valores aleatórios
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        v[i] = rand() % n + 1;
        printf("%d\n", v[i]);
    }
    for(int i = 0; i < n; i++){
        d1[i]=v[i];
        d2[i]=v[i];
        d3[i]=v[i];
        d4[i]=v[i];
    }
    int continuar=1;
    int *compara=0, *movimenta=0;

    fileEntrada(v, n);
    do
    {  
        tempo = 0;
        compara = 0;
        movimenta = 0;

        printf("\n\tExercício do cão\n\n");
        printf("1. Bubble Sort\n");
        printf("2. Seletion Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Ver o relatório\n");
        printf("6. Sair\n");

        scanf("%d", &continuar);
        system("cls || clear");

        switch(continuar)
        {
            case 1:
                fileLeitura(V2, n);
                bubblesort(d1, compara, movimenta, n);
                printf("\n\nvetor ordenado em Bubble Sort:\n");
                for(int i=0; i<n; i++){
                    printf("%d ", d1[i]);
                    d1[i]=v[i];
                    printf("\n");
                }
                break;

            case 2:
                selectionsort(d2, compara, movimenta, n);
                printf("\n\nvetor ordenado em Selection Sort:\n");
                for(int i = 0; i < n; i++){
                    printf("%d ", d2[i]);
                    d2[i]=v[i];
                    printf("\n");
                }
                break;

            case 3:
                insertionsort(d3, compara, movimenta, n);
                printf("\n\nvetor ordenado em Insertion Sort:\n");
                for(int i = 0; i < n; i++){
                    printf("%d ", d3[i]);
                    d3[i]=v[i];
                    printf("\n");
                }
                break;
            
            case 4:
                mergesort(d4, n, compara, movimenta);
                for(int i = 0; i < n; i++){
                    printf("%d ", d4[i]);
                    d4[i]=v[i];
                    printf("\n");
                }
                break;

            case 5:

                break;

                break;

            default:
                printf("Digite uma opcao valida\n");
        }
    } while(continuar);
}

/////////////////////////////////////////////////////////
