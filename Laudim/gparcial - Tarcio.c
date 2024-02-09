#include <stdio.h>

void swapEquations(float eq1[], float eq2[]) {
    float temp[4];
    for (int i = 0; i < 4; i++) {
        temp[i] = eq1[i];
        eq1[i] = eq2[i];
        eq2[i] = temp[i];
    }
}

void eliminate(float eq1[], float eq2[], float factor) {
    for (int i = 0; i < 4; i++) {
        eq2[i] = eq2[i] - factor * eq1[i];
    }
}

int main() {
    float eq1[4], eq2[4], eq3[4];
    
    printf("Informe os coeficientes da primeira equacao (ax + ay + az = d):\n");
    for (int i = 0; i < 4; i++) {
        scanf("%f", &eq1[i]);
    }
    
    printf("Informe os coeficientes da segunda equacao (bx + by + bz = f):\n");
    for (int i = 0; i < 4; i++) {
        scanf("%f", &eq2[i]);
    }
    
    printf("Informe os coeficientes da terceira equacao (cx + cy + cz = g):\n");
    for (int i = 0; i < 4; i++) {
        scanf("%f", &eq3[i]);
    }
    
    // Encontre a equação com o maior coeficiente x como pivô
    if (eq2[0] > eq1[0]) {
        swapEquations(eq1, eq2);
    }
    if (eq3[0] > eq1[0]) {
        swapEquations(eq1, eq3);
    }
    
    // Eliminação de x da segunda equação usando a primeira equação como pivô
    float factor = eq2[0] / eq1[0];
    eliminate(eq1, eq2, factor);
    
    // Eliminação de x da terceira equação usando a primeira equação como pivô
    factor = eq3[0] / eq1[0];
    eliminate(eq1, eq3, factor);
    
    // Eliminação de y da terceira equação usando a segunda equação como pivô
    factor = eq3[1] / eq2[1];
    eliminate(eq2, eq3, factor);
    
    // Resolvendo z da terceira equação
    float z = eq3[3] / eq3[2];  // coeficiente de z na terceira equação
    
    // Resolvendo y da segunda equação
    float y = (eq2[3] - eq2[2] * z) / eq2[1];  // coeficientes de y na segunda equação
    
    // Resolvendo x da primeira equação
    float x = (eq1[3] - eq1[2] * z - eq1[1] * y) / eq1[0];  // coeficientes de x na primeira equação
    
    // Exibindo as soluções
    printf("\nSolucao:\n");
    printf("x = %.8f\n", x);
    printf("y = %.8f\n", y);
    printf("z = %.8f\n", z);
    
    return 0;
}
