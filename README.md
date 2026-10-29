# Controle de Estoque — Bubble Sort x Quick Sort em C

**Disciplina:** Algoritmos e Pensamento Computacional — UDF
**Autora:** Nicole Albuquerque ([@nicolealbuquerque2006-collab](https://github.com/nicolealbuquerque2006-collab))

---

## Situação-problema

Uma loja de roupas tem dezenas de produtos e precisa repor o estoque antes que eles acabem. Olhando a lista desorganizada, é difícil perceber quais itens estão quase esgotados, e a loja corre o risco de perder vendas.

**Por que ordenar?** Ao ordenar os produtos pela **quantidade em estoque, da menor para a maior**, os itens que precisam de reposição aparecem no topo da lista. Assim, o responsável pelas compras sabe na hora o que pedir primeiro.

## Objetivo da aplicação

Desenvolver um programa em C que:

- armazene 12 produtos (nome, quantidade e preço) em um array de registros (`struct`);
- ordene **os mesmos dados** com dois algoritmos: **Bubble Sort** e **Quick Sort**;
- mostre os dados **antes** e **depois** da ordenação;
- marque como **REPOR** os produtos com menos de 10 unidades;
- compare os dois algoritmos pela quantidade de **comparações** e **trocas** realizadas.

## Como funcionam os algoritmos

### Bubble Sort

Compara **elementos vizinhos** (`j` e `j+1`) e troca os dois quando estão fora de ordem. A cada passada pelo array, o maior valor "sobe como uma bolha" até o final.

- **Laço externo:** controla as passadas (no máximo `n - 1`).
- **Laço interno:** compara os pares vizinhos até `n - 1 - i`, pois os últimos `i` elementos já estão no lugar certo.
- **Parada antecipada:** se uma passada inteira não faz nenhuma troca, o array já está ordenado e o algoritmo para.
- **Complexidade:** O(n²) no caso médio e no pior caso.

### Quick Sort

Usa a estratégia **dividir para conquistar**:

1. Escolhe um **pivô** (neste projeto, o último elemento do trecho).
2. **Particiona** o trecho: os produtos com quantidade menor que a do pivô vão para a esquerda e os maiores ficam à direita. O pivô termina na sua posição definitiva.
3. Aplica o mesmo processo, de forma **recursiva**, na parte da esquerda e na da direita, até cada parte ter 0 ou 1 elemento.

- **Complexidade:** O(n log n) no caso médio e O(n²) no pior caso.

### Comparação nos dados do projeto

| Algoritmo | Comparações | Trocas |
|---|---|---|
| Bubble Sort | 60 | 31 |
| Quick Sort | 25 | 15 |

Os dois chegam ao mesmo resultado, mas o Quick Sort faz menos da metade das comparações. Ele divide o problema em partes menores, enquanto o Bubble Sort compara os mesmos vizinhos várias vezes.

## Como executar

```bash
gcc estoque.c -o estoque
./estoque        # Linux/macOS
estoque.exe      # Windows
```

## Exemplo de uso

Ao executar o programa, aparece este menu:

```
==================================================
   CONTROLE DE ESTOQUE - LOJA DE ROUPAS
   Criterio: quantidade em estoque (CRESCENTE)
==================================================
  1 - Ordenar com Bubble Sort
  2 - Ordenar com Quick Sort
  3 - Comparar os dois algoritmos
  0 - Sair
```

Saída da opção `2` (Quick
