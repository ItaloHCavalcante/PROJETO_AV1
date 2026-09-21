#include <stdio.h>

int analisaPares(int n, int A[n][n]) {
    int contador = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int soma = A[i-1][j-1] + A[j-1][i-1];
            int resto = soma % 5;
            if (resto == 0) {
                contador++;
            }
        }
    }
    return contador;
}

/* APENAS PARA TESTES:
int main(void) {
    int matriz[3][3] = {
        {5, 2, 4},
        {3, 1, 6},
        {1, 4, 10}
    };

    int esperado = 5;
    int resultado = analisaPares(3, matriz);

    printf("Resultado esperado: %d\n", esperado);
    printf("Resultado obtido:   %d\n", resultado);

    if (resultado == esperado) {
        printf("Teste passou!\n");
        return 0;
    }

    printf("Teste falhou!\n");
    return 1;
}

*/