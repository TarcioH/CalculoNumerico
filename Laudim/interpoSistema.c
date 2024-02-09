#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_linalg.h>

// Função para resolver o sistema linear para encontrar os coeficientes do polinômio
void solveLinearSystem(int n, double *x, double *y, double *coefficients) {
    // Constrói a matriz do sistema linear A
    gsl_matrix *A = gsl_matrix_calloc(n + 1, n + 1);

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            gsl_matrix_set(A, i, j, pow(x[i], j));
        }
    }

    // Constrói o vetor do lado direito B
    gsl_vector *B = gsl_vector_calloc(n + 1);

    for (int i = 0; i <= n; ++i) {
        gsl_vector_set(B, i, y[i]);
    }

    // Aloca memória para o vetor de solução
    gsl_vector *solution = gsl_vector_calloc(n + 1);

    // Aloca memória para a permutação das linhas durante a decomposição LU
    gsl_permutation *p = gsl_permutation_calloc(n + 1);

    // Faz a decomposição LU da matriz
    int s;
    gsl_linalg_LU_decomp(A, p, &s);

    // Resolve o sistema linear
    gsl_linalg_LU_solve(A, p, B, solution);

    // Copia os resultados para o vetor de coeficientes
    for (int i = 0; i <= n; ++i) {
        coefficients[i] = gsl_vector_get(solution, i);
    }

    // Libera a memória alocada
    gsl_matrix_free(A);
    gsl_vector_free(B);
    gsl_vector_free(solution);
    gsl_permutation_free(p);
}

// Função para avaliar o polinômio interpolador
double evaluatePolynomial(int n, double *coefficients, double x) {
    double result = 0.0;

    for (int i = 0; i <= n; ++i) {
        result += coefficients[i] * pow(x, i);
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

    // Aloca memória para os coeficientes do polinômio
    double *coefficients = malloc((n + 1) * sizeof(double));

    // Resolve o sistema linear para encontrar os coeficientes
    solveLinearSystem(n, x, y, coefficients);

    // Exibe os coeficientes do polinômio interpolador
    printf("\nCoeficientes do polinomio interpolador:\n");
    for (int i = 0; i <= n; ++i) {
        printf("a%d = %.6lf\n", i, coefficients[i]);
    }

    // Avalia o polinômio interpolador em alguns pontos
    printf("\nAvaliacao do polinomio interpolador:\n");
    for (int i = 0; i <= n; ++i) {
        double result = evaluatePolynomial(n, coefficients, x[i]);
        printf("P(%.2lf) = %.6lf\n", x[i], result);
    }

    // Libera a memória alocada
    free(x);
    free(y);
    free(coefficients);

    return 0;
}
