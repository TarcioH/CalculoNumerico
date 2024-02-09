#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Informe o tamanho do sistema de equacoes: ");
    scanf("%d", &n);

    int maxIterations = 100;  // Numero maximo de iteracoes
    float tolerance = 1e-6;  // Tolerancia para convergencia

    float A[n][n];  // Matriz de coeficientes
    float b[n];     // Vetor de termos constantes
    float x[n];     // Vetor de solucoes inicial

    printf("Informe os coeficientes da matriz A (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    printf("Informe os termos constantes do sistema:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &b[i]);
    }

    for (int i = 0; i < n; i++) {
        x[i] = 0;  // Vetor de solucoes inicial
    }

    for (int iter = 0; iter < maxIterations; iter++) {
        for (int i = 0; i < n; i++) {
            float sum = 0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            x[i] = (b[i] - sum) / A[i][i];
        }

        // Verificar a convergencia
        int converged = 1;
        for (int i = 0; i < n; i++) {
            if (fabs(x[i] - x[i]) > tolerance) {
                converged = 0;
                break;
            }
        }

        if (converged) {
            printf("Convergencia atingida apos %d iteracoes.\n", iter + 1);
            break;
        }
    }

    // Exibir as solucoes
    printf("Solucao:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.8f\n", i, x[i]);
    }

    return 0;
}
