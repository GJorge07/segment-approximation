#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ponto.h"
#include "guloso.h"
#include "heap.h"

Ponto *pontos;
int n;
int area_tipo;
float tolerancia;

int main(int argc, char *argv[]){
    Heap *h;

    /* talvez tenha que usar isso aqui!! não sei
    if (argc < 3) {                 / evita acessar argv[1]/argv[2] fora dos limites /
        fprintf(stderr, "uso: %s -a|-h <tolerancia>\n", argv[0]);
        return 1;
    }
    */

    char *tipo = argv[1];           /*le -a ou -h*/

    if (strcmp(tipo, "-a") == 0 )
        area_tipo = 1;

    else if (strcmp(tipo, "-h") == 0)
        area_tipo = 0;

    else {

        fprintf(stderr, "Tipo de área inválido. Use -a para área ou -h para altura.\n");
        return 1;

    }

    tolerancia = atof(argv[2]);   /*le a tolerancia*/

    if (scanf("%d", &n) != 1 || n < 0) {   /*valida leitura de n*/
        fprintf(stderr, "Erro: leitura invalida da quantidade de pontos\n");
        return 1;
    }

    pontos = malloc(n * sizeof(Ponto));         /*alocação dos pontos*/
    if (!pontos)
        return 1;

    for (int i = 0; i < n; i++) {

        if (scanf("%f", &pontos[i].y) != 1) {   /*valida leitura de y*/
            fprintf(stderr, "Erro: leitura invalida da coordenada y do ponto %d\n", i);
            free(pontos);
            return 1;
        }
        pontos[i].x = (float)i + 1;            /*x vao de 1.0 a n*/
        pontos[i].removido = 0;
        
        if (i > 0)                      /*define anteriores*/
            pontos[i].anterior = i - 1;

        if (i < n -1)                   /*define proximos*/
            pontos[i].proximo = i + 1;
        
    }

    for (int j = 1; j < n-1; j++)           /*calcula erro*/
        pontos[j].erro = calcula_erro(j);

    /* Cria e insere pontos no heap */
    h = cria_heap(n);
    for (int j = 1; j < n - 1; j++)
        insere_heap(h, j);

    loop_guloso(h);

    /*------------------------IMPRESSAO DA SAÍDA---------------------------------*/
    int cont = 0;
    for(int p = 0; p < n; p++)  
        if (!pontos[p].removido)
            cont++;

    printf("%d\n",cont);  /*imprime quantidade de pontos nao removidos*/

    for(int w = 0; w < n; w++)
        if (!pontos[w].removido)
            printf("%.1f %g\n", pontos[w].x, pontos[w].y);  /*%g trata not cientifica*/

    destroi_heap(h);
    free(pontos);
    return 0;
}
