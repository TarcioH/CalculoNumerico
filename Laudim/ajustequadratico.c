#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ajusteQuadratico(int n, double x[], double y[], double *a, double *b, double *c) {
    double soma_x = 0.0, soma_x2 = 0.0, soma_x3 = 0.0, soma_x4 = 0.0, soma_y = 0.0, soma_xy = 0.0, soma_x2y = 0.0;

    for (int i = 0; i < n; ++i) {
        double xi = x[i];
        double xi2 = xi * xi;

        soma_x += xi;
        soma_x2 += xi2;
        soma_x3 += xi * xi2;
        soma_x4 += xi2 * xi2;

        double yi = y[i];
        soma_y += yi;
        soma_xy += xi * yi;
        soma_x2y += xi2 * yi;
    }

    // Montar o sistema de equações normais
    double sistema[3][4] = {
        {n, soma_x, soma_x2, soma_y},
        {soma_x, soma_x2, soma_x3, soma_xy},
        {soma_x2, soma_x3, soma_x4, soma_x2y}
    };

    // Aplicar a eliminação de Gauss
    for (int k = 0; k < 3; ++k) {
        for (int i = k + 1; i < 3; ++i) {
            double fator = sistema[i][k] / sistema[k][k];
            for (int j = k; j < 4; ++j) {
                sistema[i][j] -= fator * sistema[k][j];
            }
        }
    }

    // Aplicar a substituição retroativa
    *c = sistema[2][3] / sistema[2][2];
    *b = (sistema[1][3] - sistema[1][2] * (*c)) / sistema[1][1];
    *a = (sistema[0][3] - sistema[0][2] * (*c) - sistema[0][1] * (*b)) / sistema[0][0];
}

int main() {
    int n;

    printf("Digite o número de pontos de dados: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Número inválido de pontos de dados. Encerrando o programa.\n");
        return 1;
    }

    double x[n], y[n];

    printf("Digite os valores de x:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &x[i]);
    }

    printf("Digite os valores de y:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &y[i]);
    }

    double a, b, c;
    ajusteQuadratico(n, x, y, &a, &b, &c);

    printf("Ajuste Quadrático:\n");
    printf("y = %.4fx^2 + %.4fx + %.4f\n", a, b, c);

    return 0;
}
