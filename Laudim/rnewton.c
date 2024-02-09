#include <stdio.h>
#include <math.h>
#include <string.h>
#include "eval.h" // Biblioteca para avaliação de expressões matemáticas

int main() {
    char expr[100]; // String para a expressão da função
    double x0;      // Valor inicial
    double epsilon; // Tolerância para a solução
    double x;       // Valor aproximado da raiz

    printf("Informe a expressao da funcao (por exemplo, x*x - 4): ");
    scanf("%s", expr);

    printf("Informe o valor inicial [x0]: ");
    scanf("%lf", &x0);
    printf("Informe a tolerancia [epsilon]: ");
    scanf("%lf", &epsilon);

    int iter = 0;
    double result;
    
    while (1) {
        // Avalia a expressão da função
        eval(expr, &x0, &result);

        x = x0 - result / (2.0 * x0); // A derivada de x^2 é 2x

        iter++;

        if (fabs(result) < epsilon) {
            break;
        }

        x0 = x;
    }

    printf("Raiz aproximada: %lf\n", x);
    printf("Numero de iteracoes: %d\n", iter);

    return 0;
}
