#include <stdio.h>
#include <stdlib.h>

// Função para calcular o polinômio interpolador de Lagrange
double lagrangeInterpolation(int n, double *x, double *y, double xi) {
    double result = 0.0;

    for (int i = 0; i <= n; ++i) {
        double term = y[i];

        for (int j = 0; j <= n; ++j) {
            if (j != i) {
                term = term * (xi - x[j]) / (x[i] - x[j]);
            }
        }

        result += term;
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

    // Calcula o valor interpolado usando o polinômio de Lagrange
    double interpolatedValue = lagrangeInterpolation(n, x, y, xi);

    // Exibe o resultado
    printf("\nO valor interpolado em xi = %.2lf é: %.6lf\n", xi, interpolatedValue);

    // Libera a memória alocada
    free(x);
    free(y);

    return 0;
}