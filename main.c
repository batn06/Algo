#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS_A 2  // A matrisinin satır sayısı
#define COLS_A 3  // A matrisinin sütun sayısı
#define ROWS_B 3  // B matrisinin satır sayısı
#define COLS_B 2  // B matrisinin sütun sayısı

// Fonksiyon prototipleri
void randomValueGeneration(int rows, int cols, int matrix[rows][cols]);
void printMatrix(int rows, int cols, int matrix[rows][cols]);
void multiplyMatrix(int arr1[ROWS_A][COLS_A], int arr2[ROWS_B][COLS_B], int result[ROWS_A][COLS_B]);
void transposeMatrix(int rows, int cols, int matrix[rows][cols], int transposed[cols][rows]);

int main() {
    srand(time(NULL)); // Rastgele sayı üretimi için seed ayarlama

    int A[ROWS_A][COLS_A]; // 2x3 boyutunda A matrisi
    int B[ROWS_B][COLS_B]; // 3x2 boyutunda B matrisi
    int result[ROWS_A][COLS_B]; // 2x2 boyutunda sonuç matrisi
    int transposedA[COLS_A][ROWS_A]; // A matrisinin transpozu
    int transposedB[COLS_B][ROWS_B]; // B matrisinin transpozu

    // A ve B matrislerini rastgele değerlerle doldur
    randomValueGeneration(ROWS_A, COLS_A, A);
    randomValueGeneration(ROWS_B, COLS_B, B);

    // Matrisleri yazdır
    printf("Matrix A (2x3):\n");
    printMatrix(ROWS_A, COLS_A, A);

    printf("\nMatrix B (3x2):\n");
    printMatrix(ROWS_B, COLS_B, B);

    // Matrislerin çarpımını hesapla
    multiplyMatrix(A, B, result);

    // Sonuç matrisini yazdır
    printf("\nResult Matrix (Product of A and B):\n");
    printMatrix(ROWS_A, COLS_B, result);

    // A ve B matrislerinin transpozunu hesapla
    transposeMatrix(ROWS_A, COLS_A, A, transposedA);
    transposeMatrix(ROWS_B, COLS_B, B, transposedB);

    // Transpoze matrisleri yazdır
    printf("\nTransposed Matrix A (3x2):\n");
    printMatrix(COLS_A, ROWS_A, transposedA);

    printf("\nTransposed Matrix B (2x3):\n");
    printMatrix(COLS_B, ROWS_B, transposedB);

    return 0;
}

// Rastgele matris oluşturan fonksiyon
void randomValueGeneration(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10; // 0 ile 9 arasında rastgele değerler
        }
    }
}

// Matrisi ekrana yazdıran fonksiyon
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Matris çarpımı yapan fonksiyon
void multiplyMatrix(int arr1[ROWS_A][COLS_A], int arr2[ROWS_B][COLS_B], int result[ROWS_A][COLS_B]) {
    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_B; j++) {
            result[i][j] = 0; // Sonuç matrisini sıfırla
            for (int k = 0; k < COLS_A; k++) { // COLS_A, arr1'in sütun sayısı ve arr2'nin satır sayısı
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

// Matrisin transpozunu hesaplayan fonksiyon
void transposeMatrix(int rows, int cols, int matrix[rows][cols], int transposed[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j]; // Transpoz işlemi
        }
    }
}
