#include "s21_matrix_oop.h"

// using namespace std;
// int main() {
//     S21Matrix matrix1(2, 2);
//     matrix1.placeholder();
//     matrix1.printer();
//     matrix1.mul_matrix(matrix1); //= matrix1 * matrix1;
//     matrix1.printer();
// }

// Базовый конструктор
S21Matrix::S21Matrix() {
    this->rows_ = 3;
    this->cols_ = 3;
    this->matrix_ = new double *[rows_]();
    for (int i = 0; i < rows_; i++) {
        this->matrix_[i] = new double[cols_]();
    }
}

//  Параметризированный конструктор
S21Matrix::S21Matrix(int rows_, int cols_) {
    try {
        if (rows_ >= 1 && cols_ >= 1) {
            this->rows_ = rows_;
            this->cols_ = cols_;
            this->matrix_ = new double *[rows_]();
            for (int i = 0; i < rows_; i++) {
                this->matrix_[i] = new double[cols_]();
            }

        } else {
            this->matrix_ = nullptr;
            throw std::exception();
        }
    } catch (const std::exception &err) {
        std::cout << err.what() << std::endl;
    }
}

//  Конструктор копирования
// Здесь использую пример инициализации значений(это вызов базового конструктора
// внутри нашего конструктура)
S21Matrix::S21Matrix(const S21Matrix &other)
        : rows_(other.rows_), cols_(other.cols_) {
    this->matrix_ = new double *[rows_]();
    for (int i = 0; i < rows_; i++) {
        this->matrix_[i] = new double[cols_]();
    }
    for (int i = 0; i < this->rows_; i++) {
        for (int j = 0; j < this->cols_; j++) {
            this->matrix_[i][j] = other.matrix_[i][j];
        }
    }
}

//  Конструктор переноса (копия с удалением)
S21Matrix::S21Matrix(S21Matrix &&other) {
    this->rows_ = other.rows_;
    this->cols_ = other.cols_;
    this->matrix_ = other.matrix_;
    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
    if (this->matrix_) {
        for (int i = 0; i < this->rows_; i++) {
            delete this->matrix_[i];
        }
        delete this->matrix_;
    }
}

/**
 * @brief Выводит матрицу
 */
void S21Matrix::printer() {
    printf("\n");
    if (this->matrix_) {
        for (int i = 0; i < this->rows_; i++) {
            for (int j = 0; j < this->cols_; j++) {
                printf("%lf ", this->matrix_[i][j]);
            }
            printf("\n");
        }
    }
    printf("\n");
}


void S21Matrix::sum_matrix(const S21Matrix &other) {
    try {
        if (other.matrix_ && this->rows_ >= 1 && this->cols_ >= 1) {
            if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
                for (int i = 0; i < this->rows_; i++) {
                    for (int j = 0; j < this->cols_; j++) {
                        this->matrix_[i][j] =
                                this->matrix_[i][j] + other.matrix_[i][j];
                    }
                }
            } else {
                throw std::exception();
            }
        } else {
            throw std::exception();
        }
    } catch (const std::exception &err) {
        std::cout << err.what() << std::endl;
    }
}

/**
 * @brief Вычитание матриц
 * @return
 * 0 - OK
 * 1 - Ошибка, некорректная матрица
 * 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
 *     нельзя провести вычисления и т.д.)
 */
void S21Matrix::sub_matrix(const S21Matrix &other) {
    try {
        if (other.matrix_ && this->rows_ >= 1 && this->cols_ >= 1) {
            if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
                //  S21Matrix s = new S21Matrix(rows_,cols_);
                for (int i = 0; i < this->rows_; i++) {
                    for (int j = 0; j < this->cols_; j++) {
                        this->matrix_[i][j] =
                                this->matrix_[i][j] - other.matrix_[i][j];
                    }
                }
            } else {
                // flag = CALCULATION_ERROR;
                throw std::exception();
            }
        } else {
            // flag = INCORRECT_MATRIX;
            throw std::exception();
        }
    } catch (const std::exception &err) {
        std::cout << err.what() << std::endl;
    }
}

/**
 * @brief Умножение матрицы на число
 */
void S21Matrix::mul_number(const double num) {
    if (this->rows_ >= 1 && this->cols_ >= 1) {
        for (int i = 0; i < this->rows_; i++) {
            for (int j = 0; j < this->cols_; j++) {
                this->matrix_[i][j] = this->matrix_[i][j] * num;
            }
        }
    } else {
        throw std::exception();
    }
}

/**
 * @brief Умножение двух матриц
 */
void S21Matrix::mul_matrix(const S21Matrix &other) {
    try {
        if (other.rows_ >= 1 && other.cols_ >= 1 && this->rows_ >= 1 &&
            this->cols_ >= 1) {
            if (this->rows_ == other.cols_ && this->cols_ == other.rows_) {
                double result[rows_][other.cols_];
                for (int i = 0; i < this->rows_; i++) {
                    for (int j = 0; j < this->cols_; j++) {
                        result[i][j] = 0;
                        for (int k = 0; k < this->cols_; k++) {
// Проблема была в случае умножения самого на себя 
                            result[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
                        }
                    }
                }
                for (int i = 0; i < this->rows_; i++) {
                    for (int j = 0; j < this->cols_; j++) {
                        this->matrix_[i][j] = result[i][j];
                    }
                }
            } else {
                throw std::exception();
            }
        } else {
            throw std::exception();
        }
    } catch (const std::exception &err) {
        std::cout << err.what() << std::endl;
    }
}


void S21Matrix::copy_matrix(const S21Matrix &other) {
    this->rows_ = other.rows_;
    this->cols_ = other.cols_;
    this->matrix_ = new double *[rows_];
    for (int i = 0; i < rows_; i++) {
        this->matrix_[i] = new double[cols_];
    }
    for (int i = 0; i < this->rows_; i++) {
        for (int j = 0; j < this->cols_; j++) {
            this->matrix_[i][j] = other.matrix_[i][j];
        }
    }
}

/**
 * @brief Транспонирование матриц (Замена строк этой матрицы ее столбцами с
 * сохранением их номеров)
 *  создает матрицу result
 * @return
 * 0 - OK
 * 1 - Ошибка, некорректная матрица
 * 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
 *     нельзя провести вычисления и т.д.)
 */
S21Matrix S21Matrix::transpose() {
    // int flag = OK;
    S21Matrix result((S21Matrix &) *this);
    try {
        if (this->rows_ >= 1 && this->cols_ >= 1) {
            // s21_create_matrix(this->cols_, this->rows_, result);
            for (int i = 0; i < this->rows_; i++) {
                for (int j = 0; j < this->cols_; j++) {
                    this->matrix_[j][i] = result.matrix_[i][j];
                }
            }
        } else {
            throw std::exception();
        }
    } catch (const std::exception &err) {
        std::cout << err.what() << std::endl;
    }

    return *this;
}

// /**
//  * @brief Находит определитель матрицы (determinant)
//  */
double S21Matrix::determinant() {
    double result = 0;
    try {
        if (this->rows_ >= 1 && this->cols_ >= 1) {
            if (this->rows_ == this->cols_) {
                if (this->rows_ == 1) {
                    result = this->matrix_[0][0];
                } else if (this->rows_ == 2) {
                    result = this->matrix_[0][0] * this->matrix_[1][1] -
                             this->matrix_[0][1] * this->matrix_[1][0];
                } else {
                    double determinant = 0;
                    for (int j = 0; j < this->cols_; j++) {
                        S21Matrix matrix_minor(rows_ - 1, cols_ - 1);
                        minor_matrix(matrix_minor, 0, j);
                        result = matrix_minor.determinant();
                        determinant +=
                                this->matrix_[0][j] * pow(-1, j) * result;
                    }
                    result = determinant;
                }
            } else {
                throw std::exception();
            }
        } else {
            throw std::exception();
        }
    } catch (const std::exception &err) {
        std::cout << err.what() << std::endl;
    }

    return result;
}

// /**
//  * @brief Находит минор матрицы
//  */
void S21Matrix::minor_matrix(S21Matrix &result, int row, int column) {
    for (int i = 0, new_i = 0; i < this->rows_; i++) {
        if (i == row) continue;
        for (int j = 0, new_j = 0; j < this->cols_; j++) {
            if (j == column) continue;
            result.matrix_[new_i][new_j] = this->matrix_[i][j];
            new_j++;
        }
        new_i++;
    }
}

/**
 * @brief матрица алгебраических дополнений
 * создает матрицу result
 */
S21Matrix S21Matrix::calc_complements() {
    S21Matrix result(this->cols_, this->rows_);
    try {
        if (this->rows_ >= 1 && this->cols_ >= 1) {
            if (this->rows_ == this->cols_) {
                for (int i = 0; i < this->rows_; i++) {
                    for (int j = 0; j < this->cols_; j++) {
                        S21Matrix m_for_determinant(this->cols_ - 1,
                                                    this->rows_ - 1);
                        double determinant = 0;
                        this->minor_matrix(m_for_determinant, i, j);
                        determinant = m_for_determinant.determinant();
                        result.matrix_[i][j] = determinant * pow(-1, i + j);
                    }
                }
            } else {
                throw std::exception();
            }
        } else {
            throw std::exception();
        }
    } catch (const std::exception &err) {
        std::cout << err.what() << std::endl;
    }

    return result;
}

/**
 * @brief Находит обратную матрицу
 */
S21Matrix S21Matrix::inverse_matrix() {
    S21Matrix tmp(this->cols_, this->rows_);
    try {
        if (this->rows_ >= 1 && this->cols_ >= 1) {
            if (this->rows_ == this->cols_) {
                double determinant = this->determinant();
                if (fabs(determinant) <= EPS) {
                    throw std::exception();
                } else {
                    tmp = this->calc_complements();
                    tmp = tmp.transpose();
                    tmp.mul_number(1. / determinant);
                }
            } else {
                throw std::exception();
            }
        } else {
            throw std::exception();
        }
    } catch (const std::exception &err) {
        std::cout << err.what() << std::endl;
    }

    return tmp;
}

// index operator overload
int S21Matrix::operator()(int i, int j) {
    try {
        if (i >= rows_ || j >= cols_ || i < 0 || j < 0) {
            throw std::out_of_range("Incorrect input, index is out of range");
        }
    } catch (const std::exception &err) {
        std::cout << err.what() << std::endl;
    }
    return this->matrix_[i][j];
}

