#include <stdio.h>

// Função para calcular o ajuste linear usando o método dos mínimos quadrados
void ajusteLinear(int n, double x[], double y[], double *m, double *b) {
    double soma_x = 0.0, soma_y = 0.0, soma_xy = 0.0, soma_x2 = 0.0;

    // Calcular as somas necessárias
    for (int i = 0; i < n; ++i) {
        soma_x += x[i];
        soma_y += y[i];
        soma_xy += x[i] * y[i];
        soma_x2 += x[i] * x[i];
    }

    // Calcular os coeficientes
    *m = (n * soma_xy - soma_x * soma_y) / (n * soma_x2 - soma_x * soma_x);
    *b = (soma_y - *m * soma_x) / n;
}

int main() {
    int n;

    // Solicitar o número de pontos de dados
    printf("Digite o número de pontos de dados: ");
    scanf("%d", &n);

    // Verificar se o número de pontos de dados é válido
    if (n <= 0) {
        printf("Número inválido de pontos de dados. Encerrando o programa.\n");
        return 1;
    }

    // Alocar espaço para os arrays de dados
    double x[n], y[n];

    // Solicitar os valores de x e y
    printf("Digite os valores de x:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &x[i]);
    }

    printf("Digite os valores de y:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &y[i]);
    }

    // Calcular o ajuste linear
    double m, b;
    ajusteLinear(n, x, y, &m, &b);

    // Exibir os resultados
    printf("Ajuste Linear:\n");
    printf("y = %.4fx + %.4f\n", m, b);

    return 0;
}
