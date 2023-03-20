#ifndef SQMATRIX_H
#define SQMATRIX_H

#include "recmatrix.h"

class SquareMatrix : public RectangularMatrix {
public:
    // Конструкторы
    SquareMatrix();
    SquareMatrix(int size);
    SquareMatrix(const SquareMatrix& other);
    explicit SquareMatrix(const RectangularMatrix& other);


    //Оператор присваивания
    SquareMatrix& operator=(const SquareMatrix& other);

    SquareMatrix operator+(const SquareMatrix& other) const;
    SquareMatrix operator-(const SquareMatrix& other) const;
    SquareMatrix operator*(const SquareMatrix& other) const;
    SquareMatrix operator/(const double scalar) const;

    // Обратная матрица
    SquareMatrix inverse() const;
    double determinant() const;
    SquareMatrix get_minor(int row, int col) const;
    double cofactor(int row, int col) const;
    SquareMatrix operator*(const double scalar) const;

};

#endif // SQMATRIX_H
