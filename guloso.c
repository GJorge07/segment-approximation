#include "ponto.h"
#include "heap.h"
#include "guloso.h"

void loop_guloso() {

    // -------chamar heap_construir() aqui-------------

    while (1) {

        //-------------------substituir linha abaixo por heap_extrair_min()---------------------
        int i = 0; // placeholder, remover quando heap estiver pronto

        if (pontos[i].erro >= tolerancia)  /*se o menor erro do heap'ja for maior, todos os outros serão*/
            break;

        /*remove o ponto*/
        int ant  = pontos[i].anterior;
        int prox = pontos[i].proximo;

        pontos[ant].proximo = prox;
        pontos[prox].anterior = ant;
        pontos[i].removido = 1;         
        
        if (ant != 0)       /*se nao é o primeiro elemento*/
            pontos[ant].erro = calcula_erro(ant);

        if (prox != n - 1)  /*se nao é o ultimo elemento*/
            pontos[prox].erro = calcula_erro(prox);

        //------------------ chamar heap_atualizar(ant) aqui-------------------
        //-------------------chamar heap_atualizar(prox) aqui-------------------

    }
}