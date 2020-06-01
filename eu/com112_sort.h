#ifndef _SORT
#define _SORT

void bubblesort(int *v, int *compara, int *movimento, int n);
void selectionsort(int *v, int *compara, int *movimento, int n);
void insertionsort(int *v, int *compara, int *movimento, int n);
void mergesort(int *v, int n, int *compara, int *movimento);
void merge(int *v, int *c, int i, int m, int f, int *compara, int *movimento);
void sort(int *v, int *c, int i, int f, int *compara, int *movimento);

void menu();












#endif