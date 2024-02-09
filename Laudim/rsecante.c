#include <stdio.h>
#include <string.h>
#include "muParser.h"

// Função que avalia a expressão da função
double evaluate_function(mup::ParserX& parser, const char* expression, double x) {
    parser.DefineVar("x", &x);
    parser.SetExpr(expression);
    return parser.Eval();
}

int main() {
    mup::ParserX parser;
    
    char expr[100]; // String para a expressão da função
    double x0, x1;   // Valores iniciais
    double epsilon;  // Tolerância para a solução
    double x;        // Valor aproximado da raiz

    printf("Informe a expressao da funcao (por exemplo, x*x - 4): ");
    scanf("%s", expr);

    printf("Informe o primeiro valor inicial [x0]: ");
    scanf("%lf", &x0);
    printf("Informe o segundo valor inicial [x1]: ");
    scanf("%lf", &x1);
    printf("Informe a tolerancia [epsilon]: ");
    scanf("%lf", &epsilon);

    int iter = 0;
    while (1) {
        double fx0 = evaluate_function(parser, expr, x0);
        double fx1 = evaluate_function(parser, expr, x1);
        
        x = x1 - fx1 * (x1 - x0) / (fx1 - fx0);
        iter++;

        if (fx1 == 0 || fabs(x - x1) < epsilon) {
            break;
        }

        x0 = x1;
        x1 = x;
    }

    printf("Raiz aproximada: %lf\n", x);
    printf("Numero de iteracoes: %d\n", iter);

    return 0;
}
