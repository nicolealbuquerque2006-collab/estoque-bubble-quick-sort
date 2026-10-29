/*
 * ============================================================
 *  Projeto: Controle de Estoque - Bubble Sort x Quick Sort
 *  Disciplina: Algoritmos e Pensamento Computacional - UDF
 *  Autora: Nicole Albuquerque
 *
 *  Situacao-problema: uma loja de roupas precisa saber quais
 *  produtos estao acabando para fazer a reposicao a tempo.
 *  Ordenando os produtos pela quantidade em estoque (da menor
 *  para a maior), os que precisam ser repostos aparecem primeiro.
 *
 *  O programa ordena OS MESMOS DADOS com dois algoritmos:
 *  Bubble Sort e Quick Sort, e compara quantas comparacoes e
 *  trocas cada um precisou fazer.
 * ============================================================
 */

#include <stdio.h>

#define TAM 12            /* quantidade de produtos (minimo exigido: 10) */
#define TAM_NOME 30       /* tamanho maximo do nome do produto           */
#define ESTOQUE_MINIMO 10 /* abaixo disso o produto precisa de reposicao */

/* Cada registro (produto) guarda nome, quantidade e preco */
typedef struct {
    char nome[TAM_NOME];
    int quantidade;
    float preco;
} Produto;

/* Contadores usados para comparar o desempenho dos algoritmos */
int comparacoes = 0;
int trocas = 0;

/* ---------- Prototipos das funcoes ---------- */
void copiarProdutos(Produto origem[], Produto destino[], int n);
void mostrarProdutos(Produto p[], int n);
void trocar(Produto *a, Produto *b);
void bubbleSort(Produto p[], int n);
void quickSort(Produto p[], int inicio, int fim);
int particionar(Produto p[], int inicio, int fim);
void executarBubble(Produto original[]);
void executarQuick(Produto original[]);

int main(void) {
    /* Array com os 12 registros ORIGINAIS (desordenados).
       Ele nunca e alterado: cada algoritmo ordena uma COPIA,
       assim os dois trabalham sempre com os mesmos dados. */
    Produto estoque[TAM] = {
        {"Camiseta basica",    25, 39.90f},
        {"Calca jeans",         8, 129.90f},
        {"Vestido longo",       3, 219.90f},
        {"Jaqueta corta-vento", 14, 189.90f},
        {"Short de linho",      6, 89.90f},
        {"Blusa de tricot",    19, 99.90f},
        {"Saia midi",           2, 119.90f},
        {"Bermuda moletom",    31, 69.90f},
        {"Camisa social",      11, 149.90f},
        {"Moletom canguru",     5, 159.90f},
        {"Regata dry fit",     42, 34.90f},
        {"Macacao",             9, 199.90f}
    };
    executarBubble(estoque);
    executarQuick(estoque);

    return 0;
}

/* ============================================================
 *  BUBBLE SORT
 *  Compara elementos VIZINHOS (j e j+1) e troca os dois quando
 *  estao fora de ordem. A cada passada, o maior valor "sobe como
 *  uma bolha" para o final do array.
 *  Complexidade: O(n^2) no pior caso e no caso medio.
 * ============================================================ */
void bubbleSort(Produto p[], int n) {
    int i, j, trocou;

    /* Laco externo: cada volta e uma "passada" pelo array.
       Sao necessarias no maximo n-1 passadas. */
    for (i = 0; i < n - 1; i++) {
        trocou = 0;

        /* Laco interno: compara os pares vizinhos.
           Vai ate n-1-i porque os ultimos i elementos ja estao
           na posicao final (as "bolhas" que ja subiram). */
        for (j = 0; j < n - 1 - i; j++) {
            comparacoes++;

            /* Se o da esquerda tem MAIS estoque que o da direita,
               estao fora de ordem: troca os dois de lugar. */
            if (p[j].quantidade > p[j + 1].quantidade) {
                trocar(&p[j], &p[j + 1]);
                trocou = 1;
            }
        }

        /* Se uma passada inteira nao fez nenhuma troca,
           o array ja esta ordenado e o algoritmo pode parar. */
        if (!trocou) {
            break;
        }
    }
}

/* ============================================================
 *  QUICK SORT
 *  Estrategia "dividir para conquistar":
 *   1. Escolhe um elemento chamado PIVO (aqui, o ultimo).
 *   2. Particiona: coloca os menores que o pivo a esquerda e os
 *      maiores a direita. O pivo fica na sua posicao definitiva.
 *   3. Repete o processo (recursao) em cada lado do pivo.
 *  Complexidade: O(n log n) no caso medio, O(n^2) no pior caso.
 * ============================================================ */
void quickSort(Produto p[], int inicio, int fim) {
    int posPivo;

    /* Caso base: se o trecho tem 0 ou 1 elemento, ja esta ordenado */
    if (inicio < fim) {
        /* Separa o trecho e descobre onde o pivo ficou */
        posPivo = particionar(p, inicio, fim);

        /* Ordena recursivamente a parte da esquerda (menores) */
        quickSort(p, inicio, posPivo - 1);

        /* Ordena recursivamente a parte da direita (maiores) */
        quickSort(p, posPivo + 1, fim);
    }
}

/* Particionamento (esquema de Lomuto):
   percorre o trecho e leva para a esquerda todos os produtos
   com quantidade MENOR que a do pivo. */
int particionar(Produto p[], int inicio, int fim) {
    int pivo = p[fim].quantidade;  /* pivo = ultimo elemento do trecho */
    int i = inicio - 1;            /* fim da regiao dos "menores"      */
    int j;

    for (j = inicio; j < fim; j++) {
        comparacoes++;

        /* Se o elemento atual e menor que o pivo,
           aumenta a regiao dos menores e coloca ele la dentro. */
        if (p[j].quantidade < pivo) {
            i++;
            if (i != j) {
                trocar(&p[i], &p[j]);
            }
        }
    }

    /* Coloca o pivo logo depois da regiao dos menores:
       essa e a posicao definitiva dele no array ordenado. */
    if (i + 1 != fim) {
        trocar(&p[i + 1], &p[fim]);
    }
    return i + 1;
}

/* Troca dois produtos de posicao usando uma variavel auxiliar.
   Como o registro inteiro e trocado, nome, quantidade e preco
   continuam sempre juntos. */
void trocar(Produto *a, Produto *b) {
    Produto aux = *a;
    *a = *b;
    *b = aux;
    trocas++;
}

/* Copia os registros originais para outro array, para que
   cada algoritmo ordene os MESMOS dados de partida. */
void copiarProdutos(Produto origem[], Produto destino[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

/* Mostra os produtos em forma de tabela */
void mostrarProdutos(Produto p[], int n) {
    int i;

    printf("%-4s %-22s %6s %10s   %s\n", "Pos", "Produto", "Qtd", "Preco", "Situacao");
    for (i = 0; i < n; i++) {
        printf("%-4d %-22s %6d %10.2f   %s\n", i + 1, p[i].nome,
               p[i].quantidade, p[i].preco,
               p[i].quantidade < ESTOQUE_MINIMO ? "REPOR" : "OK");
    }
}

void executarBubble(Produto original[]) {
    Produto copia[TAM];
    copiarProdutos(original, copia, TAM);

    printf("\n------------ DADOS ANTES DA ORDENACAO ------------\n");
    mostrarProdutos(copia, TAM);

    comparacoes = 0;
    trocas = 0;
    bubbleSort(copia, TAM);

    printf("\n------ DADOS APOS A ORDENACAO (BUBBLE SORT) ------\n");
    mostrarProdutos(copia, TAM);
    printf("\nComparacoes: %d | Trocas: %d\n", comparacoes, trocas);
    printf("Produtos com menos de %d unidades devem ser repostos (REPOR).\n",
           ESTOQUE_MINIMO);
}

void executarQuick(Produto original[]) {
    Produto copia[TAM];
    copiarProdutos(original, copia, TAM);

    printf("\n------------ DADOS ANTES DA ORDENACAO ------------\n");
    mostrarProdutos(copia, TAM);

    comparacoes = 0;
    trocas = 0;
    quickSort(copia, 0, TAM - 1);

    printf("\n------ DADOS APOS A ORDENACAO (QUICK SORT) -------\n");
    mostrarProdutos(copia, TAM);
    printf("\nComparacoes: %d | Trocas: %d\n", comparacoes, trocas);
    printf("Produtos com menos de %d unidades devem ser repostos (REPOR).\n",
           ESTOQUE_MINIMO);
}

