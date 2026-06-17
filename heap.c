#include <stdlib.h>

#include "heap.h"
#include "ponto.h"

Heap *cria_heap(int n) {
    Heap *heap;

    if(!(heap = malloc(sizeof(Heap))))
        return NULL;

    if(!(heap->v = malloc(sizeof(No) * n))){
        free(heap);
        heap = NULL;

        return NULL;
    }

    return heap;
}

void insere_heap(int indice_ponto) {


}

int  extrai_min_heap() {


}

void atualiza_heap(int indice_ponto) {

}