#ifndef PONTO_H
#define PONTO_H

typedef struct {

    float x, y;
    float erro;
    int removido;
    int anterior;
    int proximo;

} Ponto;


float area_triangulo(float x1, float y1, float x2, float y2, float x3, float y3);
float altura2_triangulo(float x1, float y1, float x2, float y2, float x3, float y3);
float calcula_erro(int i);

#endif