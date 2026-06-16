#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "guloso.h"


int main(int argc, char *argv[]){


    char *tipo = argv[1];           /*le -a ou -h*/

    if (strcmp(tipo, "-a") == 0 )
        area_tipo = 1;

    else if (strcmp(tipo, "-h") == 0)
        area_tipo = 0;

    else {

        printf("erro");
        return 0;

    }

    tolerancia = atof(argv[2]);   /*le a tolerancia*/

    scanf("%d",&n);

    pontos = malloc(n * sizeof(Ponto));         /*alocação dos pontos*/
    if (!pontos)
        return 1;

    for (int i = 0; i < n; i++) {

        scanf("%f", &pontos[i].y);       /*le os y*/
        pontos[i].x = (float)i + 1;            /*x vao de 1.0 a n*/
        pontos[i].removido = 0;
        
        if (i > 0)                      /*define anteriores*/
            pontos[i].anterior = i - 1;

        if (i < n -1)                   /*define proximos*/
            pontos[i].proximo = i + 1;
        
    }

    for (int j = 1; j < n-1; j++)           /*calcula erro*/
        pontos[j].erro = calcula_erro(j);


    /*--------FALTA HEAP CONSTRUIR E HEAP GULOSO AQUI AINDA ------------------*/

    /*------------------------IMPRESSAO DA SAÍDA---------------------------------*/
    int cont = 0;
    for(int p = 0; p < n; p++)  
        if (!pontos[p].removido)
            cont ++;

    printf("%d\n",cont);  /*imprime quantidade de pontos nao removidos*/

    for(int w = 0; w < n; w++)
        if (!pontos[w].removido)
            printf("%.1f %g\n", pontos[w].x, pontos[w].y);  /*%g trata not cientifica*/

    free(pontos);
    return 0;
}
