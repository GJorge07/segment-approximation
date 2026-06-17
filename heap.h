#ifndef HEAP_H
#define HEAP_H

typedef struct{
    int indice;
    float erro; /*prioridade*/
} No;

typedef struct{
    No *heap;
    int tam;
} Fila_Prio;

void cria_heap();
void insere_heap(int indice_ponto);
int  extrai_min_heap();
void atualiza_heap(int indice_ponto);

#endif