#include "recmatrix.h"

// Конструктор по умолчанию
RectangularMatrix::RectangularMatrix() {
    this->rows = 0;
    this->cols = 0;
    this->data = nullptr;
}

// Конструктор с заданными размерами
RectangularMatrix::RectangularMatrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;

    // Выделение памяти под матрицу
    this->data = new double*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->data[i] = new double[this->cols];
        for (int j = 0; j < this->cols; j++) {
            this->data[i][j] = 0;
        }
    }
}

// Конструктор копирования
RectangularMatrix::RectangularMatrix(const RectangularMatrix& other) {
    this->rows = other.rows;
    this->cols = other.cols;
    this->data = new double*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->data[i] = new double[this->cols];
        for (int j = 0; j < this->cols; j++) {
            this->data[i][j] = other.data[i][j];
        }
    }
}

// Деструктор
RectangularMatrix::~RectangularMatrix() {
    for (int i = 0; i < this->rows; i++) {
        delete[] this->data[i];
    }
    delete[] this->data;
}

// Оператор присваивания
RectangularMatrix& RectangularMatrix::operator=(const RectangularMatrix& other) {
    if (this == &other) {
        return *this;
    }

    if (this->rows != other.rows || this->cols != other.cols) {
        throw "Matrices have different sizes";
    }

    // Освобождаем старую память
    for (int i = 0; i < this->rows; i++) {
        delete[] this->data[i];
    }
    delete[] this->data;

    // Выделяем новую память
    this->data = new double*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->data[i] = new double[this->cols];
    }

    // Копируем данные
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            this->data[i][j] = other.data[i][j];
        }
    }

    return *this;
}


// Оператор сложения матриц
RectangularMatrix RectangularMatrix::operator+(const RectangularMatrix& other) const {
    if (this->rows != other.rows || this->cols != other.cols) {
        throw "Matrices have different sizes";
    }
    RectangularMatrix result(this->rows, this->cols);
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            result.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }
    return result;
}

//Оператор вычитания
RectangularMatrix RectangularMatrix::operator-(const RectangularMatrix& other) const {
    if (this->rows != other.rows || this->cols != other.cols) {
        throw "Matrices have different sizes";
    }
    RectangularMatrix result(this->rows, this->cols);
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            result.data[i][j] = this->data[i][j] - other.data[i][j];
        }
    }
    return result;
}

RectangularMatrix RectangularMatrix::operator*(const RectangularMatrix& other) const {
    if (this->cols != other.rows) {
        throw "The number of columns of the first matrix does not match the number of rows of the second matrix";
    }
    RectangularMatrix result(this->rows, other.cols);
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            double sum = 0.0;
            for (int k = 0; k < this->cols; k++) {
                sum += this->data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

RectangularMatrix RectangularMatrix::operator*(const int scalar) const {
    RectangularMatrix result(this->rows, this->cols);
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            result.data[i][j] = this->data[i][j] * scalar;
        }
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const RectangularMatrix& matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            os << matrix.data[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

double* RectangularMatrix::operator[](const int row) const {
    if (row < 0 || row >= this->rows) {
        throw "Incorrect row index";
    }
    return this->data[row];
}