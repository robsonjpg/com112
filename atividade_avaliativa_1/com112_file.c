#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "com112_file.h"
void abrirArquivoEntrada(int var[], int quantidade)
{
    FILE *arquivo;
    int i;
    arquivo = fopen("com112_entrada.txt", "wt");

    if (arquivo == NULL)
    {
        printf("ERRO AO ABRIR ARQUIVO!");
        
    }
    else
    {

        fprintf(arquivo, "%d\n", quantidade);
        for (i = 0; i < quantidade; i++)
        {
            fprintf(arquivo, "%d ", var[i]);
        }

        fclose(arquivo);
        
    }
}

void abrirArquivoSaida(int var[], int quantidade)
{
    FILE *arquivo;
    int i;
    arquivo = fopen("com112_saida.txt", "wt");

    if (arquivo == NULL)
    {
        printf("ERRO AO ABRIR ARQUIVO!");
        
    }
    else
    {

        fprintf(arquivo, "%d\n", quantidade);
        for (i = 1; i < quantidade + 1; i++)
        {
            fprintf(arquivo, "%d ", var[i]);
        }

        fclose(arquivo);
        
    }
}

int *lerArquivoEntrada()
{
    FILE *arquivo;
    char *result;
    int *vet;
    arquivo = fopen("com112_entrada.txt", "rt");

    if (arquivo == NULL)
    {
        printf("ERRO AO ABRIR ARQUIVO!");
        fclose(arquivo);
        return NULL;
    }
    else
    {
        char linha[50];
        int cont = 0, quant, i;
        printf("Arquivo aberto com sucesso!\n");
        while (!feof(arquivo))
        {

            if (cont == 0)
            {
                fscanf(arquivo, "%d", &quant);
                cont++;
                vet = malloc((quant + 16) * sizeof(int));
                vet[0] = quant;
            }
            else
            {

                for (i = 1; i < (quant + 1); i++)
                {
                    fscanf(arquivo, "%d", &vet[i]);
                    //printf("%d ", vet[i]);
                }
            }
        }
        for(i=quant+1;i<quant+16;i++){
            vet[i] = 0;
        }
        return vet;
        fclose(arquivo);
    }
}

void escreverArquivoRelatorio(int var[])
{
    FILE *arquivo;
    int i;
    arquivo = fopen("com112_relatorio.txt", "wt");

    if (arquivo == NULL)
    {
        printf("ERRO AO ABRIR ARQUIVO!");
        
    }
    else
    {
        
        int q = var[0];
        fprintf(arquivo,"Numero de elementos ordenados: %d\n",var[0]);
        fprintf(arquivo,"Metodo Bubble Sort               \n");
        fprintf(arquivo,"    Tempo de execucão: %f        \n",(var[q+7])/100000000.0);
        fprintf(arquivo,"    Numero de comparacoes %d     \n",var[q+1]);
        fprintf(arquivo,"    Numero de movimentacoes: %d  \n",var[q+2]);
        fprintf(arquivo,"Metodo Selection Sort            \n");
        fprintf(arquivo,"    Tempo de execucão: %f        \n",(var[q+8])/100000000.0);
        fprintf(arquivo,"    Numero de comparacoes %d     \n",var[q+3]);
        fprintf(arquivo,"    Numero de movimentacoes: %d  \n",var[q+4]);
        fprintf(arquivo,"Metodo Insertion Sort            \n");
        fprintf(arquivo,"    Tempo de execucão: %f        \n",(var[q+9])/100000000.0);
        fprintf(arquivo,"    Numero de comparacoes %d     \n",var[q+5]);
        fprintf(arquivo,"    Numero de movimentacoes: %d  \n",var[q+6]);
        fprintf(arquivo,"Metodo Merge Sort            \n");
        fprintf(arquivo,"    Tempo de execucão: %f        \n",(var[q+12])/100000000.0);
        fprintf(arquivo,"    Numero de comparacoes %d     \n",var[q+10]);
        fprintf(arquivo,"    Numero de movimentacoes: %d  \n",var[q+11]);
        fprintf(arquivo,"Metodo Quick Sort            \n");
        fprintf(arquivo,"    Tempo de execucão: %f        \n",(var[q+13])/100000000.0);
        fprintf(arquivo,"    Numero de comparacoes %d     \n",var[q+14]);
        fprintf(arquivo,"    Numero de movimentacoes: %d  \n",var[q+15]);


        fclose(arquivo);
        
    }
}

void lerArquivoRelatorio()
{
    FILE *arquivo;
    char *result;
    arquivo = fopen("com112_relatorio.txt", "rt");

    if (arquivo == NULL)
    {
        printf("ERRO AO ABRIR ARQUIVO!");
        fclose(arquivo);
        
    }
    else
    {
        
        size_t t = 50;
        char* linha=malloc(t);
        printf("Arquivo aberto com sucesso!\n");
        while (!feof(arquivo))
        {
            getline(&linha, &t, arquivo);
            printf("%s",linha);
        }
        
    }
    fclose(arquivo);
}