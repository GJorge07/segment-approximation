#ifndef HEAP_H
#define HEAP_H

typedef struct{
    int indice;
    float erro; /*prioridade*/
} No;

typedef struct{
    No *v;
    int tam;
} Heap;

Heap *cria_heap(int n);

void insere_heap(Heap *heap, int indice_ponto);

int extrai_min_heap(Heap *heap);

void atualiza_heap(int indice_ponto);

Heap *destroi_heap();

#endif