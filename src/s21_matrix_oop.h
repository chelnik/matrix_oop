#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

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

class S21Matrix {
   private:
    // Attributes
    int rows_, cols_;  // Rows and columns
    double** matrix_;  // Pointer to the memory where the matrix is allocated

    void memory_allocation();
    void destroy_matrix();
    void copy_matrix(const S21Matrix& other);

   public:
    S21Matrix();  // Default constructor
    S21Matrix(int rows_, int cols_);  //  Параметризированный конструктор
                                      //  c количеством строк и столбцов
    S21Matrix(const S21Matrix& other);  //  Конструктор копирования
    S21Matrix(S21Matrix&& other);  //  Конструктор переноса (копия с удалением)
    ~S21Matrix();  // Destructor

    void printer();
    void placeholder();
    void placeholder_for_determinant();
    void placeholder_for_inverse();
    void set_num(int i, int j, double num);

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

    S21Matrix operator+(const S21Matrix& o);
    S21Matrix& operator+=(const S21Matrix& o);
    S21Matrix operator-(const S21Matrix& o);
    S21Matrix& operator-=(const S21Matrix& o);
    S21Matrix operator*(const S21Matrix& o);
    S21Matrix& operator*=(const S21Matrix& o);
    bool operator==(const S21Matrix& o);
    S21Matrix& operator=(const S21Matrix& o);

    int operator()(int i, int j);  // index operator overload
    int get_rows();
    int get_cols();
    void set_rows(int row);
    void set_cols(int col);
};

#endif  // SRC_S21_MATRIX_OOP_H_
