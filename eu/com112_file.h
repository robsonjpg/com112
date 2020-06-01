#ifndef COM112_FILE
#define COM112_FILE

//Função para ler o arquivo com112_entrada.txt, onde estão os elementos a serem ordenados
//Jogando esses elementos para um vetor
void fileLeitura(int *V2, int n);

//Registrar os resultados obtidos em Bubble Sort no arquivo com112_relatorio.txt
void fileBubble(double tempo, int compara, int movimenta);

//Registrar os resultados obtidos em Selection Sort no arquivo com112_relatorio.txt
void fileSelection(double tempo, int compara, int movimenta);

//Registrar os resultados obtidos em Insertion Sort no arquivo com112_relatorio.txt
void fileInsertion(double tempo, int compara, int movimenta);

void fileMerge(double tempo, int compara, int movimenta);

//Registra os elementos desordenados em com112_entrada.txt
void fileEntrada(int *V, int n);

//Registra os elementos depois de terem sidos ordenados no arquivo com112_saida.txt
void fileSaida(int *V2, int n);

#endif