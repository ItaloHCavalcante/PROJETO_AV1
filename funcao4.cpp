
#include <stdio.h>
#include <limits.h>

int calcular_fatorial(int n, long long *fat) {
    *fat = 1;

    if (n < 0) {
        return 0;
    }

    for (int i = 2; i <= n; i++) {
        if (*fat > LLONG_MAX / i) {
            return 0;
        }

        *fat *= i;
    }

    return 1;
}

int processar_vetor(int n, int V[], long long *resultado) {
    long long somatotal = 0;
    long long fat;

    for (int i = 0; i < n; i++) {

        if (V[i] < 0) {
            return 0;
        }

        if (V[i] % 2 == 0) {
            fat = V[i];
        } else {
            if (!calcular_fatorial(V[i], &fat)) {
                return 0;
            }
        }

        if (somatotal > LLONG_MAX - fat) {
            return 0;
        }

        somatotal += fat;
    }

    *resultado = somatotal;
    return 1;
}