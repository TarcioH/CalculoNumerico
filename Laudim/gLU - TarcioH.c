#include <stdio.h>
#include <math.h>

void luDecomposition(float A[][3], float L[][3], float U[][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            U[i][j] = A[i][j];
            L[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    for (int k = 0; k < n - 1; k++) {
        int maxRow = k;
        float maxVal = fabs(U[k][k]);
        for (int i = k + 1; i < n; i++) {
            if (fabs(U[i][k]) > maxVal) {
                maxRow = i;
                maxVal = fabs(U[i][k]);
            }
        }

        if (maxRow != k) {
            for (int j = k; j < n; j++) {
                float temp = U[k][j];
                U[k][j] = U[maxRow][j];
                U[maxRow][j] = temp;
            }
            for (int j = 0; j < k; j++) {
                float temp = L[k][j];
                L[k][j] = L[maxRow][j];
                L[maxRow][j] = temp;
            }
        }

        for (int i = k + 1; i < n; i++) {
            float factor = U[i][k] / U[k][k];
            L[i][k] = factor;
            for (int j = k; j < n; j++) {
                U[i][j] -= factor * U[k][j];
            }
        }
    }
}

int main() {
    int n = 3;
    float A[3][3];  // Matriz de coeficientes

    printf("Informe os coeficientes da matriz A (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    float L[3][3] = {0};
    float U[3][3] = {0};

    luDecomposition(A, L, U, n);

    printf("Matriz L:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", L[i][j]);
        }
        printf("\n");
    }

    printf("Matriz U:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", U[i][j]);
        }
        printf("\n");
    }

    return 0;
}
