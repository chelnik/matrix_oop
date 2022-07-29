#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix &o) {
    S21Matrix result(*this);
    result.sum_matrix(o);
    return result;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &o) {
    this->sum_matrix(o);
    return *this;
}

S21Matrix S21Matrix::operator-(const S21Matrix &o) {
    S21Matrix result(*this);
    result.sub_matrix(o);
    return result;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &o) {
    this->sub_matrix(o);
    return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix &o) {
    S21Matrix result(*this);
    result.mul_matrix(o);
    return result;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &o) {
    this->mul_matrix(o);
    return *this;
}

/**
 * @brief Сравнение матриц
 * @return 1 - Совпадают, 0 - Не совпадают
 */
bool S21Matrix::eq_matrix(const S21Matrix &other) {
    bool flag = SUCCESS;
    if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
        for (int i = 0; i < this->rows_; i++) {
            for (int j = 0; j < this->cols_; j++) {
                if (fabs(this->matrix_[i][j] - other.matrix_[i][j]) > EPS) {
                    flag = FAILURE;
                }
            }
        }
    } else {
        flag = FAILURE;
    }
    return flag;
}

bool S21Matrix::operator==(const S21Matrix &o) { return this->eq_matrix(o); }

// занулить старую
// создать новый
// и положить в него значение
S21Matrix &S21Matrix::operator=(const S21Matrix &o) {
    if (this->matrix_) {
        for (int i = 0; i < this->rows_; i++) {
            delete this->matrix_[i];
        }
        delete this->matrix_;
    }
    this->copy_matrix(o);
    return *this;
}