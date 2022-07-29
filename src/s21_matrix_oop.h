#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

// #include <limits.h>
// #include <math.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
#include <cmath>
#include <iostream>
#include <stdexcept>
// для арифметики
#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2
// для сравнения
#define SUCCESS 1
#define FAILURE 0
#define EPS 1e-7
using namespace std;

class S21Matrix {
   private:
    // Attributes
    int rows_, cols_;  // Rows and columns
    double** matrix_;  // Pointer to the memory where the matrix is allocated

   public:
    S21Matrix();  // Default constructor
    S21Matrix(int rows_, int cols_);  //  Параметризированный конструктор
                                      //  количеством строк и столбцов
    S21Matrix(const S21Matrix& other);  //  Конструктор копирования
    S21Matrix(S21Matrix&& other);  //  Конструктор переноса (копия с удалением)
    ~S21Matrix();  // Destructor

    void printer();
    void placeholder();
    void placeholder_for_inverse();
    bool eq_matrix(const S21Matrix& other);
    void sum_matrix(const S21Matrix& other);
    void sub_matrix(const S21Matrix& other);
    void mul_number(const double num);
    void mul_matrix(const S21Matrix& other);
    S21Matrix transpose();
    S21Matrix calc_complements();
    double determinant();
    S21Matrix inverse_matrix();
    void minor_matrix(S21Matrix& result, int row, int column);

    void copy_matrix(const S21Matrix& other);

    S21Matrix operator+(const S21Matrix& o);
    S21Matrix& operator+=(const S21Matrix& o);
    S21Matrix operator-(const S21Matrix& o);
    S21Matrix& operator-=(const S21Matrix& o);
    S21Matrix operator*(const S21Matrix& o);
    S21Matrix& operator*=(const S21Matrix& o);
    bool operator==(const S21Matrix& o);
    S21Matrix& operator=(const S21Matrix& o);
    int get_row();
    int get_col();
    void set_row(int i);
    void set_col(int j);
    // index operator overload
    int operator()(int i, int j);

    // (int i, int j)
};
// class myexception : public std::exception{
//     public:
//     myexception(char *msg):std::exception(msg)
//     {

//     }
//     private:
// };

#endif  // SRC_S21_MATRIX_OOP_H_
