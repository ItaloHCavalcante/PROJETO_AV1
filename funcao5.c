#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vetor[meio] == valor) {
            return 1;
        }

        if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return 0;
}

int contarElementosPresentes(int A[], int B[], int n) {
    int contador = 0;

    for (int i = 0; i < n; i++) {
        if (buscaBinaria(B, n, A[i])) {
            contador++;
        }
    }

    return contador;
}

void preencherManual(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

void preencherAleatorio(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 100;
    }
}

int comparar(const void *a, const void *b) {
    int valorA = *(const int *)a;
    int valorB = *(const int *)b;

    return (valorA > valorB) - (valorA < valorB);
}

void imprimirVetor(int vetor[], int n) {
    printf("[ ");

    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    printf("]\n");
}

void executarFuncao5() {
    int n;
    int opcao;

    printf("\n--- FUNCAO 5 ---\n");

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);

    int *A = malloc(n * sizeof(int));
    int *B = malloc(n * sizeof(int));

    if (A == NULL || B == NULL) {
        printf("Erro ao alocar memoria.\n");
        free(A);
        free(B);
        return;
    }

    printf("\n1 - Preencher manualmente\n");
    printf("2 - Preencher automaticamente\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        printf("\nPreenchendo vetor A:\n");
        preencherManual(A, n);

        printf("\nPreenchendo vetor B:\n");
        preencherManual(B, n);
    } else if (opcao == 2) {
        preencherAleatorio(A, n);
        preencherAleatorio(B, n);
    } else {
        printf("Opcao invalida.\n");
        free(A);
        free(B);
        return;
    }

    // B precisa estar ordenado para a busca binaria funcionar
    qsort(B, n, sizeof(int), comparar);

    printf("\nVetor A:\n");
    imprimirVetor(A, n);

    printf("\nVetor B ordenado:\n");
    imprimirVetor(B, n);

    int resultado = contarElementosPresentes(A, B, n);

    printf("\nTotal de elementos de A encontrados em B: %d\n", resultado);

    free(A);
    free(B);
}