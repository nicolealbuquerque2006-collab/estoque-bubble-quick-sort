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

/* ---------- Prototipos das funcoes ---------- */
void mostrarProdutos(Produto p[], int n);

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
    printf("Estoque cadastrado:\n");
    mostrarProdutos(estoque, TAM);

    return 0;
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
