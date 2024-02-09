#include <stdio.h>
#include <math.h>

// Função cuja raiz queremos encontrar
double f(double x) {
    return x * x - 4; // Exemplo: encontrar a raiz de x^2 - 4 = 0
}

int main() {
    double a, b;     // Limites do intervalo [a, b]
    double epsilon;  // Tolerância para a solução
    double x;        // Valor aproximado da raiz

    printf("Informe o limite inferior do intervalo [a]: ");
    scanf("%lf", &a);
    printf("Informe o limite superior do intervalo [b]: ");
    scanf("%lf", &b);
    printf("Informe a tolerancia [epsilon]: ");
    scanf("%lf", &epsilon);

    if (f(a) * f(b) >= 0) {
        printf("O metodo da bisseccao nao pode ser aplicado neste intervalo.\n");
        return 1;
    }

    int iter = 0;
    while ((b - a) / 2.0 > epsilon) {
        x = (a + b) / 2.0;
        if (f(x) == 0) {
            break;
        } else if (f(x) * f(a) < 0) {
            b = x;
        } else {
            a = x;
        }
        iter++;
    }

    printf("Raiz aproximada: %lf\n", x);
    printf("Numero de iteracoes: %d\n", iter);

    return 0;
}
