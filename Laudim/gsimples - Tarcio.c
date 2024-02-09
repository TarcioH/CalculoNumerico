#include <stdio.h>

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
    
    // Eliminação de x da segunda equação usando a primeira equação
    float factor = eq2[0] / eq1[0];
    eliminate(eq1, eq2, factor);
    
    // Eliminação de x da terceira equação usando a primeira equação
    factor = eq3[0] / eq1[0];
    eliminate(eq1, eq3, factor);
    
    // Eliminação de y da terceira equação usando a segunda equação
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
