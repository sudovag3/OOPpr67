#include "sqmatrix.h"
#include <cmath>

// Конструкторы
SquareMatrix::SquareMatrix() : RectangularMatrix() {}

SquareMatrix::SquareMatrix(int size) : RectangularMatrix(size, size) {}

SquareMatrix::SquareMatrix(const SquareMatrix& other) : RectangularMatrix(other) {}

SquareMatrix::SquareMatrix(const RectangularMatrix& other) : RectangularMatrix(other) {
    if (other.rows != other.cols) {
        throw std::invalid_argument("Cannot convert a non-square RectangularMatrix to a SquareMatrix");
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = other[i][j];
        }
    }
}

SquareMatrix SquareMatrix::operator*(const double scalar) const {
    RectangularMatrix result = RectangularMatrix::operator*(scalar);
    return SquareMatrix(result);
}

SquareMatrix SquareMatrix::operator+(const SquareMatrix& other) const {
    RectangularMatrix result = RectangularMatrix::operator+(other);
    return SquareMatrix(result);
}

SquareMatrix SquareMatrix::operator-(const SquareMatrix& other) const {
    RectangularMatrix result = RectangularMatrix::operator-(other);
    return SquareMatrix(result);
}

SquareMatrix SquareMatrix::operator*(const SquareMatrix& other) const {
    RectangularMatrix result = RectangularMatrix::operator*(other);
    return SquareMatrix(result);
}

// Оператор присваивания
SquareMatrix& SquareMatrix::operator=(const SquareMatrix& other) {
    RectangularMatrix::operator=(other);
    return *this;
}

SquareMatrix SquareMatrix::operator/(const double scalar) const {
    RectangularMatrix result = RectangularMatrix::operator/(scalar);
    return SquareMatrix(result);
}


// Обратная матрица
SquareMatrix SquareMatrix::inverse() const {
    // Проверяем, что матрица квадратная
    if (rows != cols) {
        throw std::invalid_argument("Matrix is not square");
    }

    // Вычисляем определитель матрицы
    double det = determinant();

    // Проверяем, что определитель не равен нулю
    if (det == 0) {
        throw std::invalid_argument("Matrix is not invertible");
    }

    // Создаем матрицу алгебраических дополнений
    SquareMatrix adj(rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            adj[i][j] = cofactor(j, i);
        }
    }

    // Делим матрицу алгебраических дополнений на определитель
    SquareMatrix inverse = adj / det;
    return inverse;
}

// Метод вычисления определителя квадратной матрицы
double SquareMatrix::determinant() const {
    if (rows == 1) {
        return data[0][0];
    }
    else {
        double det = 0;
        for (int j = 0; j < rows; j++) {
            SquareMatrix minor = get_minor(0, j);

            // Вычисление определителя минора с рекурсивным вызовом функции determinant()
            // Умножение значения элемента на определитель минора и добавление его к det
            // с учетом знака, определяемого через pow(-1, j)
            det += pow(-1, j) * data[0][j] * minor.determinant();
        }

        return det;
    }
}


// Метод получения минора матрицы
SquareMatrix SquareMatrix::get_minor(int row, int col) const {
    // Создание новой квадратной матрицы размером на 1 меньше исходной
    SquareMatrix minor(rows - 1);

    int mrow = 0;

    for (int i = 0; i < rows; i++) {
        // Если текущая строка не равна строке, которую нужно удалить
        if (i != row) {
            int mcol = 0;
            for (int j = 0; j < rows; j++) {
                // Если текущий столбец не равен столбцу, который нужно удалить
                if (j != col) {
                    // Присвоение элемента исходной матрицы элементу минора
                    minor.data[mrow][mcol] = data[i][j];
                    mcol++;
                }
            }
            mrow++;
        }
    }
    return minor;
}


// Метод получения алгебраического дополнения матрицы
double SquareMatrix::cofactor(int row, int col) const {
    SquareMatrix minor = get_minor(row, col);
    return pow(-1, row + col) * minor.determinant();
}


