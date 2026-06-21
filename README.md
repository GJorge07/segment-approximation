Trabalho de Algoritmos e Estrutura de Dados 3 -> 2026/1

Autores: Arthur Nickel, Bruno Hayashi, Gabriel Jorge e Luiz mo

-------------------------------------------------------------------

O programa recebe uma série de valores numéricos representando pontos
em um plano cartesiano e reduz o número de segmentos de reta necessários
para representá-la, removendo os pontos menos relevantes com base em
um critério de tolerância.

A remoção é feita por um algoritmo guloso que usa uma fila de prioridade
(min-heap), garantindo custo total de O(n log n).

Sobre testes:
Os testes foram feitos a mão e são possíveis de se localizar no diretório 
MinimumTests.Em /scripts existe um arquivo chamado 'rodar_testes_basicos.sh"; 
esse, executa os testes feitos e utiliza do valgrind para encontrar erros, 
com a ajuda da IA, automatizou-se o processo de leitura do log do valgrind,
assim, escrevendo apenas o resultado que interessa "passou" ou "não passou".

Além disso, para provar que o programa roda em O(N lgN), criou-se dois scripts 
com auxílio da IA. O /scripts/gerar_grandes_entradas.sh gera 3 arquivos em 
/TimeTests, um arquivo contém 10 mil pontos, outro 100 mil outro 1 milhão. 
Existe também, o /scripts/rodar_testes_tempo.sh, que com o comando "time"
executa o programa para esses arquivos e mostra o tempo que demorou para 
rodá-los. Dessa forma, é possível ver que o tempo está longe de ser quadrático,
ou qualquer outro, se aproxima muito do O(N logN).


## Como compilar
make

## Como executar
./programa -a <tolerancia> < entrada.txt
./programa -h <tolerancia> < entrada.txt

## Exemplo
./programa -a 10.5 < testes/entrada1.txt

## Como executar testes básicos
make
make testes

## Como executar teste de tempo
make
make tempo

## Como remover os objetos
make clean

## Como remover os objetos + arquivos gerados
make limpa
