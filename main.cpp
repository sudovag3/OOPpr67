#include <iostream>
#include "recmatrix.h"

int main() {
    // Создание матрицы 3х3 с начальными значениями 0
    RectangularMatrix matrix1(3, 3);

    matrix1[0][0] = 2;
    matrix1[0][1] = 4;
    matrix1[0][2] = 8;
    matrix1[1][0] = 10;
    matrix1[1][1] = 2;
    matrix1[1][2] = 4;
    matrix1[2][0] = 8;
    matrix1[2][1] = 10;
    matrix1[2][2] = 10;

    // Создание матрицы 3х3 с начальными значениями 1
    RectangularMatrix matrix2(3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix2[i][j] = 1;
        }
    }

    // Создание матрицы 3х2 с начальными значениями 2
    RectangularMatrix matrix3(3, 2);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            matrix3[i][j] = 2;
        }
    }

    // Вывод матриц на экран
    std::cout << "Matrix 1:" << std::endl;
    std::cout << matrix1 << std::endl;
    std::cout << "Matrix 2:" << std::endl;
    std::cout << matrix2 << std::endl;
    std::cout << "Matrix 3:" << std::endl;
    std::cout << matrix3 << std::endl;

    // Сложение матриц
    std::cout << "Matrix 1 + Matrix 2:" << std::endl;
    RectangularMatrix matrix_sum = matrix1 + matrix2;
    std::cout << matrix_sum << std::endl;

    // Вычитание матриц
    std::cout << "Matrix 2 - Matrix 1:" << std::endl;
    RectangularMatrix matrix_diff = matrix2 - matrix1;
    std::cout << matrix_diff << std::endl;

    // Умножение матриц
    std::cout << "Matrix 1 * Matrix 3:" << std::endl;
    RectangularMatrix matrix_prod = matrix1 * matrix3;
    std::cout << matrix_prod << std::endl;

    // Умножение матрицы на скаляр
    std::cout << "Matrix 2 * 2:" << std::endl;
    RectangularMatrix matrix_scalar_prod = matrix2 * 2;
    std::cout << matrix_scalar_prod << std::endl;

    return 0;
}
