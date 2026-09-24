#include <stdio.h>
#include <stdlib.h>

int compararMatrizes3D(int n, int A[n][n][n], int B[n][n][n]) {
    long long somaA = 0;
    long long somaB = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                somaA += A[i][j][k];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                somaB += B[i][j][k];
            }
        }
    }

    if (somaA >= somaB) {
        return 1;
    }

    return 0;
}

void preencherManual3D(int n, int M[n][n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                printf("Digite o valor [%d][%d][%d]: ", i, j, k);
                scanf("%d", &M[i][j][k]);
            }
        }
    }
}

void preencherAleatorio3D(int n, int M[n][n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                M[i][j][k] = rand() % 100;
            }
        }
    }
}

void imprimirMatriz3D(int n, int M[n][n][n]) {
    for (int i = 0; i < n; i++) {
        printf("\nCamada %d:\n", i);

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                printf("%d ", M[i][j][k]);
            }

            printf("\n");
        }
    }
}

void executarFuncao3() {
    int n;
    int opcao;

    printf("\n--- FUNCAO 3 ---\n");

    printf("Digite o tamanho n das matrizes tridimensionais: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Tamanho invalido.\n");
        return;
    }

    int (*A)[n][n] = malloc(n * sizeof *A);
    int (*B)[n][n] = malloc(n * sizeof *B);

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
        printf("\nPreenchendo matriz A:\n");
        preencherManual3D(n, A);

        printf("\nPreenchendo matriz B:\n");
        preencherManual3D(n, B);

    } else if (opcao == 2) {
        preencherAleatorio3D(n, A);
        preencherAleatorio3D(n, B);

    } else {
        printf("Opcao invalida.\n");

        free(A);
        free(B);

        return;
    }

    printf("\nMatriz A:\n");
    imprimirMatriz3D(n, A);

    printf("\nMatriz B:\n");
    imprimirMatriz3D(n, B);

    int resultado = compararMatrizes3D(n, A, B);

    if (resultado == 1) {
        printf("\nA soma de A e maior ou igual a soma de B.\n");
    } else {
        printf("\nA soma de A e menor que a soma de B.\n");
    }

    printf("Resultado: %d\n", resultado);

    free(A);
    free(B);
}