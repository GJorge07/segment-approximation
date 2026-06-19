#include <stdlib.h>

#include "heap.h"
#include "ponto.h"

void sacode_heap(Heap *heap, int i){
    No aux;
    i *= 2;

    while(i <= heap->tam){
        if(i < heap->tam && heap->v[i].erro > heap->v[i+1].erro)
            i++;

        if(heap->v[i/2].erro <= heap->v[i].erro) /*e heap*/
            break;

        aux = heap->v[i/2];
        heap->v[i/2] = heap->v[i];
        heap->v[i] = aux;
        i *= 2;
    }
}

Heap *cria_heap(int n) {
    Heap *heap;

    if(!(heap = malloc(sizeof(Heap))))
        return NULL;

    if(!(heap->v = malloc(sizeof(No) * (n + 1)))){
        free(heap);
        heap = NULL;

        return NULL;
    }

    heap->tam = 0;

    return heap;
}

void insere_heap(Heap *heap, int indice_ponto) {
    No novo, aux;

    novo.indice = indice_ponto;
    novo.erro = pontos[indice_ponto].erro;
    
    heap->tam++;
    heap->v[heap->tam] = novo; /*insere no final do heap*/

    int i = heap->tam;
    while(heap->v[i].erro < heap->v[i/2].erro){
        aux = heap->v[i/2];
        heap->v[i/2] = heap->v[i];
        heap->v[i] = aux;
        i /= 2;
    }
}

int extrai_min_heap(Heap *heap) {
    int removido = heap->v[1].indice;

    if(heap->tam != 0)
        heap->v[1] = heap->v[heap->tam];

    heap->tam--;

    sacode_heap(heap, 1);

    return removido;
}

void atualiza_heap(int indice_ponto) {

}

Heap *destroi_heap(Heap *heap) {
    free(heap->v);
    heap->v = NULL;

    free(heap);
    heap = NULL;

    return heap;
}