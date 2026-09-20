#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VALOR_ALEATORIO_MAXIMO 99


void preencherVetorManual(int vetor[], int tamanho, const char *nome) {
    for (int i = 0; i < tamanho; i++) {
        printf("%s[%d]: ", nome, i);
        scanf("%d", &vetor[i]);
    }
}

void preencherVetorAleatorio(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % (VALOR_ALEATORIO_MAXIMO + 1);
    }
}

void imprimirVetor(const int vetor[], int tamanho, const char *nome) {
    printf("\n%s = [", nome);
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

long long contarOcorrencias(const int vetor[], int n,
                            const int buscados[], int k) {
    long long total = 0;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (buscados[i] == vetor[j]) {
                total++;
            }
        }
    }

    return total;
}

int lerModoPreenchimento(void) {
    int modo;

    do {
        printf("\nEscolha o modo de preenchimento:\n");
        printf("1 - Manual\n");
        printf("2 - Automatico com valores aleatorios\n");
        printf("Opcao: ");
        scanf("%d", &modo);

        if (modo != 1 && modo != 2) {
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (modo != 1 && modo != 2);

    return modo;
}

void executarFuncao1(int modoPreenchimento) {
    int n;
    int k;

    printf("\n--- Funcao 1: Contagem de Ocorrencias Distintas ---\n");
    printf("Informe o tamanho n do vetor principal: ");
    scanf("%d", &n);
    printf("Informe a quantidade k de elementos buscados: ");
    scanf("%d", &k);

    if (n <= 0 || k <= 0) {
        printf("Os tamanhos n e k devem ser maiores que zero.\n");
        return;
    }

    int *vetor = malloc((size_t)n * sizeof(int));
    int *buscados = malloc((size_t)k * sizeof(int));

    if (vetor == NULL || buscados == NULL) {
        printf("Nao foi possivel alocar memoria para os vetores.\n");
        free(vetor);
        free(buscados);
        return;
    }

    if (modoPreenchimento == 1) {
        printf("\nPreenchimento do vetor principal:\n");
        preencherVetorManual(vetor, n, "V");

        printf("\nPreenchimento do vetor de elementos buscados:\n");
        preencherVetorManual(buscados, k, "B");
    } else {
        preencherVetorAleatorio(vetor, n);
        preencherVetorAleatorio(buscados, k);
    }

    /* O enunciado exige a impressao dos arranjos antes do resultado. */
    imprimirVetor(vetor, n, "Vetor principal");
    imprimirVetor(buscados, k, "Elementos buscados");

    clock_t inicio = clock();
    long long resultado = contarOcorrencias(vetor, n, buscados, k);
    clock_t fim = clock();

    double tempoMedido = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\nTotal de ocorrencias: %lld\n", resultado);
    printf("Tempo medido da Funcao 1: %.6f segundo(s)\n", tempoMedido);

    free(vetor);
    free(buscados);
}

void exibirFuncaoPendente(int numero) {
    printf("\nA Funcao %d sera inserida pelo integrante responsavel.\n", numero);
}

int main(void) {
    int opcao;

    srand((unsigned int)time(NULL));

    do {
        printf(" PROJETO AV01 - COMPLEXIDADE DE ALGORITMOS\n");
        printf("-----------------------------------------------\n");
        printf("1 - Contagem de Ocorrencias Distintas\n");
        printf("2 - Analise de Pares em Matriz Triangular\n");
        printf("3 - Comparacao de Matrizes Tridimensionais\n");
        printf("4 - Analise de Casos Assimetricos\n");
        printf("5 - Elementos Presentes em Vetor Ordenado\n");
        printf("0 - Encerrar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 5) {
            int modoPreenchimento = lerModoPreenchimento();

            switch (opcao) {
                case 1:
                    executarFuncao1(modoPreenchimento);
                    break;
                case 2:
                case 3:
                case 4:
                case 5:
                    exibirFuncaoPendente(opcao);
                    break;
            }
        } else if (opcao != 0) {
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    printf("\nPrograma encerrado.\n");
    return 0;
}
