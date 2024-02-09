#include <stdio.h>

void rowOperation(float matrix[][4], int sourceRow, int targetRow, float factor) {
    for (int i = 0; i < 4; i++) {
        matrix[targetRow][i] -= factor * matrix[sourceRow][i];
    }
}

void divideRow(float matrix[][4], int row, float divisor) {
    for (int i = 0; i < 4; i++) {
        matrix[row][i] /= divisor;
    }
}

int main() {
    float matrix[3][4];  // 3x4 matrix for coefficients and solutions
    
    printf("Informe os coeficientes da primeira equacao (ax + by + cz = d):\n");
    for (int i = 0; i < 4; i++) {
        scanf("%f", &matrix[0][i]);
    }

    printf("Informe os coeficientes da segunda equacao (ax + by + cz = d):\n");
    for (int i = 0; i < 4; i++) {
        scanf("%f", &matrix[1][i]);
    }
    
    printf("Informe os coeficientes da terceira equacao (ax + by + cz = d):\n");
    for (int i = 0; i < 4; i++) {
        scanf("%f", &matrix[2][i]);
    }
    
    // Aplicar o método de Gauss-Jordan
    for (int pivotRow = 0; pivotRow < 3; pivotRow++) {
        divideRow(matrix, pivotRow, matrix[pivotRow][pivotRow]);
        for (int targetRow = 0; targetRow < 3; targetRow++) {
            if (targetRow != pivotRow) {
                rowOperation(matrix, pivotRow, targetRow, matrix[targetRow][pivotRow]);
            }
        }
    }
    
    // Exibir os valores das variáveis
    printf("\nSolucao:\n");
    printf("x = %.8f\n", matrix[0][3]);
    printf("y = %.8f\n", matrix[1][3]);
    printf("z = %.8f\n", matrix[2][3]);
    
    return 0;
}
