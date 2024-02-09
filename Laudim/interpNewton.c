#include <stdio.h>
#include <stdlib.h>

// Função para calcular o polinômio interpolador de Newton
double newtonInterpolation(int n, double *x, double *y, double xi) {
    double result = y[0];
    double term = 1.0;

    for (int i = 1; i <= n; ++i) {
        term *= (xi - x[i - 1]);

        double dividedDiff = 0.0;
        for (int j = 0; j <= i; ++j) {
            double termProduct = 1.0;
            for (int k = 0; k <= i; ++k) {
                if (k != j) {
                    termProduct *= (x[j] - x[k]);
                }
            }
            dividedDiff += y[j] / termProduct;
        }

        result += term * dividedDiff;
    }

    return result;
}

int main() {
    int n;

    // Solicita a quantidade de pontos
    printf("Digite a quantidade de pontos: ");
    scanf("%d", &n);

    // Aloca memória para armazenar os valores de x e f(x)
    double *x = malloc((n + 1) * sizeof(double));
    double *y = malloc((n + 1) * sizeof(double));

    // Solicita os valores de x e f(x)
    for (int i = 0; i <= n; ++i) {
        printf("Digite o valor de x%d: ", i);
        scanf("%lf", &x[i]);
        printf("Digite o valor de f(x%d): ", i);
        scanf("%lf", &y[i]);
    }

    // Solicita o ponto de interpolação
    double xi;
    printf("\nDigite o ponto de interpolação xi: ");
    scanf("%lf", &xi);

    // Calcula o valor interpolado usando o polinômio de Newton
    double interpolatedValue = newtonInterpolation(n, x, y, xi);

    // Exibe o resultado
    printf("\nO valor interpolado em xi = %.2lf é: %.6lf\n", xi, interpolatedValue);

    // Libera a memória alocada
    free(x);
    free(y);

    return 0;
}
