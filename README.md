# Controle de Estoque — Bubble Sort x Quick Sort em C

**Disciplina:** Algoritmos e Pensamento Computacional — UDF
**Autora:** Nicole Albuquerque ([@nicolealbuquerque2006-collab](https://github.com/nicolealbuquerque2006-collab))

🔗 **Executar online:** COLE_AQUI_O_LINK_DO_ONLINEGDB

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

### Online (sem instalar nada)
Acesse o link do OnlineGDB no topo desta página e clique em **Run**.

### No computador

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

Saída da opção `2` (Quick Sort), após a tabela "antes":

```
------ DADOS APOS A ORDENACAO (QUICK SORT) -------
Pos  Produto                   Qtd      Preco   Situacao
1    Saia midi                   2     119.90   REPOR
2    Vestido longo               3     219.90   REPOR
3    Moletom canguru             5     159.90   REPOR
4    Short de linho              6      89.90   REPOR
5    Calca jeans                 8     129.90   REPOR
6    Macacao                     9     199.90   REPOR
7    Camisa social              11     149.90   OK
8    Jaqueta corta-vento        14     189.90   OK
9    Blusa de tricot            19      99.90   OK
10   Camiseta basica            25      39.90   OK
11   Bermuda moletom            31      69.90   OK
12   Regata dry fit             42      34.90   OK

Comparacoes: 25 | Trocas: 15
```

## Tecnologias

- Linguagem **C** (biblioteca `stdio.h`)
- Compilador **GCC**
- **OnlineGDB** para execução online
- **Git** e **GitHub** para versionamento
