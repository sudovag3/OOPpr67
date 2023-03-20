#ifndef RECMATRIX_H
#define RECMATRIX_H

#include <iostream>
using namespace std;

class RectangularMatrix {
public:
    int rows, cols; // количество строк и столбцов матрицы
    double **data; // указатель на массив данных матрицы
    // Конструкторы
    RectangularMatrix();
    RectangularMatrix(int rows, int cols);
    RectangularMatrix(const RectangularMatrix& other);
    
    // Деструктор
    ~RectangularMatrix();
    
    // Оператор сложения двух матриц
    RectangularMatrix operator+(const RectangularMatrix& other) const;
    
    // Оператор вычитания матриц
    RectangularMatrix operator-(const RectangularMatrix& other) const;
    
    //Оператор умножения двух матриц
    RectangularMatrix operator*(const RectangularMatrix& other) const;
    
    //Оператор умножения матрицы на скаляр
    RectangularMatrix operator*(const int scalar) const;
    
    //Оператор присваивания
    RectangularMatrix& operator=(const RectangularMatrix& other);

    RectangularMatrix operator/(const double scalar) const;
    
    // Метод получения строки матрицы с заданным номером 
    double* operator[](const int row) const;

    // Метод транспонирования матрицы
    RectangularMatrix transpose() const;

    // Вывод матрицы
    friend std::ostream& operator<<(std::ostream& os, const RectangularMatrix& matrix);
};

#endif
