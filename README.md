Trabalho de Algoritmos e Estrutura de Dados 3 -> 2026/1

Autores: Arthur Nickel, Bruno Hayashi, Gabriel Jorge e Luiz mo

-------------------------------------------------------------------

O programa recebe uma série de valores numéricos representando pontos
em um plano cartesiano e reduz o número de segmentos de reta necessários
para representá-la, removendo os pontos menos relevantes com base em
um critério de tolerância.

A remoção é feita por um algoritmo guloso que usa uma fila de prioridade
(min-heap), garantindo custo total de O(n log n).


## Como compilar
make

## Como executar
./programa -a <tolerancia> < entrada.txt
./programa -h <tolerancia> < entrada.txt

## Exemplo
./programa -a 10.5 < testes/entrada1.txt