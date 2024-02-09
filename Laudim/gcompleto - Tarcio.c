#include <stdio.h>

void swapRows(float matrix[][4], int row1, int row2) {
    float temp[4];
    for (int i = 0; i < 4; i++) {
        temp[i] = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp[i];
    }
}

void eliminate(float matrix[][4], int pivotRow, int targetRow) {
    float pivot = matrix[pivotRow][pivotRow];
    float factor = matrix[targetRow][pivotRow] / pivot;
    for (int i = pivotRow; i < 4; i++) {
        matrix[targetRow][i] = matrix[targetRow][i] - factor * matrix[pivotRow][i];
    }
}

int main() {
    float matrix[3][4];
    
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
    
    // Eliminação Gaussiana com Pivotamento Parcial
    for (int pivotRow = 0; pivotRow < 3; pivotRow++) {
        int maxRow = pivotRow;
        for (int i = pivotRow + 1; i < 3; i++) {
            if (matrix[i][pivotRow] > matrix[maxRow][pivotRow]) {
                maxRow = i;
            }
        }
        swapRows(matrix, pivotRow, maxRow);
        
        for (int targetRow = pivotRow + 1; targetRow < 3; targetRow++) {
            eliminate(matrix, pivotRow, targetRow);
        }
    }
    
    // Substituição Inversa
    float solutions[3];
    for (int i = 2; i >= 0; i--) {
        float sum = matrix[i][3];
        for (int j = i + 1; j < 3; j++) {
            sum -= matrix[i][j] * solutions[j];
        }
        solutions[i] = sum / matrix[i][i];
    }
    
    // Exibindo as soluções
    printf("\nSolucao:\n");
    printf("x = %.8f\n", solutions[0]);
    printf("y = %.8f\n", solutions[1]);
    printf("z = %.8f\n", solutions[2]);
    
    return 0;
}
