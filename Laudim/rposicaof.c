#include <stdio.h>
#include <math.h>
#include "eval.h" // Biblioteca para avaliação de expressões matemáticas

// Função de exemplo que irá avaliar a expressão
double evaluate_function(const char *expression, double x) {
    double result;
    eval(expression, x, &result);
    return result;
}

int main() {
    char expr[100]; // String para a expressão da função
    double a, b;   // Limites do intervalo [a, b]
    double epsilon;  // Tolerância para a solução
    double x;        // Valor aproximado da raiz

    printf("Informe a expressao da funcao (por exemplo, x*x - 4): ");
    scanf("%s", expr);

    printf("Informe o limite inferior do intervalo [a]: ");
    scanf("%lf", &a);
    printf("Informe o limite superior do intervalo [b]: ");
    scanf("%lf", &b);
    printf("Informe a tolerancia [epsilon]: ");
    scanf("%lf", &epsilon);

    if (evaluate_function(expr, a) * evaluate_function(expr, b) >= 0) {
        printf("O metodo da posicao falsa nao pode ser aplicado neste intervalo.\n");
        return 1;
    }

    int iter = 0;
    while (fabs(b - a) > epsilon) {
        x = (a * evaluate_function(expr, b) - b * evaluate_function(expr, a)) /
            (evaluate_function(expr, b) - evaluate_function(expr, a));
        iter++;

        if (evaluate_function(expr, x) == 0) {
            break;
        } else if (evaluate_function(expr, x) * evaluate_function(expr, a) < 0) {
            b = x;
        } else {
            a = x;
        }
    }

    printf("Raiz aproximada: %lf\n", x);
    printf("Numero de iteracoes: %d\n", iter);

    return 0;
}
