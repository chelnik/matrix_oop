
/**
 * @brief Сложение матриц
 * @return
 * 0 - OK
 * 1 - Ошибка, некорректная матрица
 * 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
 *     нельзя провести вычисления и т.д.)
 */
int s21_sum_matrix(matrix_t *this, matrix_t *other, matrix_t *result) {
    int flag = OK;
    if (this && other && result && this->rows_ >= 1 && this->cols_ >= 1) {
        if (this->rows_ == other->rows_ && this->cols_ == other->cols_) {
            s21_create_matrix(this->rows_, this->cols_, result);
            for (int i = 0; i < this->rows_; i++) {
                for (int j = 0; j < this->cols_; j++) {
                    result->matrix_[i][j] = this->matrix_[i][j] + other->matrix_[i][j];
                }
            }
        } else {
            flag = CALCULATION_ERROR;
        }
    } else {
        flag = INCORRECT_MATRIX;
    }
    return flag;
}

/**
 * @brief Вычитание матриц
 * @return
 * 0 - OK
 * 1 - Ошибка, некорректная матрица
 * 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
 *     нельзя провести вычисления и т.д.)
 */
int s21_sub_matrix(matrix_t *this, matrix_t *other, matrix_t *result) {
    int flag = OK;
    if (this && other && result && this->rows_ >= 1 && this->cols_ >= 1) {
        if (this->rows_ == other->rows_ && this->cols_ == other->cols_) {
            s21_create_matrix(this->rows_, this->cols_, result);
            for (int i = 0; i < this->rows_; i++) {
                for (int j = 0; j < this->cols_; j++) {
                    result->matrix_[i][j] = this->matrix_[i][j] - other->matrix_[i][j];
                }
            }
        } else {
            flag = CALCULATION_ERROR;
        }
    } else {
        flag = INCORRECT_MATRIX;
    }
    return flag;
}

/**
 * @brief Умножение матрицы на число
 */
int s21_mult_number(matrix_t *this, double number, matrix_t *result) {
    int flag = OK;
    if (this && result) {
        if (this->rows_ >= 1 && this->cols_ >= 1) {
            s21_create_matrix(this->rows_, this->cols_, result);
            for (int i = 0; i < this->rows_; i++) {
                for (int j = 0; j < this->cols_; j++) {
                    result->matrix_[i][j] = this->matrix_[i][j] * number;
                }
            }
        } else {
            // flag = CALCULATION_ERROR;
            flag = INCORRECT_MATRIX;
        }
    } else {
        flag = INCORRECT_MATRIX;
    }
    return flag;
}

/**
 * @brief Умножение двух матриц
 */
int s21_mult_matrix(matrix_t *this, matrix_t *other, matrix_t *result) {
    double sum = 0;
    if (this && other && result && other->rows_ >= 1 && other->cols_ >= 1 && this->rows_ >= 1 &&
        this->cols_ >= 1) {
        if (this->rows_ == other->cols_ && this->cols_ == other->rows_) {
            for (int i = 0; i < this->rows_; i++) {
                for (int j = 0; j < other->cols_; j++) {
                    for (int k = 0; k < this->cols_; k++) {
                        sum += this->matrix_[i][k] * other->matrix_[k][j];
                    }
                    result->matrix_[i][j] = sum;
                    sum = 0;
                }
            }
        } else {
            flag = CALCULATION_ERROR;
        }
    } else {
        flag = INCORRECT_MATRIX;
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
int s21_transpose(matrix_t *this, matrix_t *result) {
    int flag = OK;
    if (this && result) {
        if (this->rows_ >= 1 && this->cols_ >= 1) {
            s21_create_matrix(this->cols_, this->rows_, result);
            for (int i = 0; i < this->rows_; i++) {
                for (int j = 0; j < this->cols_; j++) {
                    result->matrix_[j][i] = this->matrix_[i][j];
                }
            }
        } else {
            // flag = CALCULATION_ERROR;
            flag = INCORRECT_MATRIX;
            // set_zero(result);
        }
    } else {
        // set_zero(result);
        flag = INCORRECT_MATRIX;
    }
    return flag;
}

/**
 * @brief Находит определитель матрицы (determinant)
 */
int s21_determinant(matrix_t *this, double *result) {
    // ДОБАВИТЬ ПРОВЕРКИ КАК ВО ВСЕХ ФУНКЦИЯХ И ОБРАБОТКУ ОШИБОК!!!
    int flag = OK;
    // *result = 0;

    if (this && result && this->rows_ >= 1 && this->cols_ >= 1) {
        if (this->rows_ == this->cols_) {
            if (this->rows_ == 1) {
                *result = this->matrix_[0][0];
            } else if (this->rows_ == 2) {
                *result = this->matrix_[0][0] * this->matrix_[1][1] -
           this->matrix_[0][1] * this->matrix_[1][0];
            } else {
                double determinant = 0;
                for (int j = 0; j < this->cols_; j++) {
                    matrix_t matrix_minor;
                    s21_create_matrix(this->rows_ - 1, this->cols_ - 1,
                                      &matrix_minor);
                    minor_matrix(this, &matrix_minor, 0, j);
                    s21_determinant(&matrix_minor, result);
                    determinant += this->matrix_[0][j] * pow(-1, j) * (*result);
                    s21_remove_matrix(&matrix_minor);
                }
                *result = determinant;
            }
        } else {
            flag = CALCULATION_ERROR;
        }

    } else {
        flag = INCORRECT_MATRIX;
    }

    return flag;
}
/**
 * @brief Находит минор матрицы
 */
void minor_matrix(matrix_t *this, matrix_t *result, int row, int column) {
    for (int i = 0, new_i = 0; i < this->rows_; i++) {
        if (i == row) continue;
        for (int j = 0, new_j = 0; j < this->cols_; j++) {
            if (j == column) continue;
            result->matrix_[new_i][new_j] = this->matrix_[i][j];
            new_j++;
        }
        new_i++;
    }
}

/**
 * @brief матрица алгебраических дополнений
 * создает матрицу result
 */
int s21_calc_complements(matrix_t *this, matrix_t *result) {
    int flag = OK;
    if (this && result && this->rows_ >= 1 && this->cols_ >= 1) {
        if (this->rows_ == this->cols_) {
            matrix_t m_for_determinant;
            s21_create_matrix(this->cols_, this->rows_, result);
            for (int i = 0; i < this->rows_; i++) {
                for (int j = 0; j < this->cols_; j++) {
                    s21_create_matrix(this->cols_ - 1, this->rows_ - 1,
                                      &m_for_determinant);
                    double determinant = 0;
                    minor_matrix(this, &m_for_determinant, i, j);
                    s21_determinant(&m_for_determinant, &determinant);
                    s21_remove_matrix(&m_for_determinant);
                    result->matrix_[i][j] = determinant * pow(-1, i + j);
                }
            }
        } else {
            flag = CALCULATION_ERROR;
        }
    } else {
        flag = INCORRECT_MATRIX;
    }
    return flag;
}

/**
 * @brief Находит обратную матрицу
 */
int s21_inverse_matrix(matrix_t *this, matrix_t *result) {
    int flag = OK;
    if (this && result && this->rows_ >= 1 && this->cols_ >= 1) {
        if (this->rows_ == this->cols_) {
            double determinant = 0;
            s21_determinant(this, &determinant);
            if (fabs(determinant) <= EPS) {
                flag = CALCULATION_ERROR;
            } else {
                matrix_t tmp;
                matrix_t tmp1;
// Когда-то тут была огромная ошибка с потерей памяти в куче
                s21_calc_complements(this, &tmp);
                s21_transpose(&tmp, &tmp1);
                s21_mult_number(&tmp1, 1. / determinant, result);

                s21_remove_matrix(&tmp);
                s21_remove_matrix(&tmp1);
            }

        } else {
            flag = CALCULATION_ERROR;
        }
    } else {
        flag = INCORRECT_MATRIX;
    }
    return flag;
}

/**
 * @brief Сравнение матриц
 * @return 1 - Совпадают, 0 - Не совпадают
 */
// int s21_eq_matrix(matrix_t *A, matrix_t *B) {
//     if (A && B) {
//         if (A->rows == B->rows && A->columns == B->columns) {
//             for (int i = 0; i < A->rows; i++) {
//                 for (int j = 0; j < A->columns; j++) {
//                     if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS)
//                         flag = FAILURE;
//                 }
//             }
//         } else {
//             // flag = FAILURE;
//         }
//     } else {
//         // flag = FAILURE;
//     }
// }






// подсказка при создаии 
            //  S21Matrix s = new S21Matrix(rows_,cols_);





//      S21Matrix bob(0,0);
// //     S21Matrix margaret(5, 5);
// //     margaret.placeholder();
// //     margaret.printer();
// //     S21Matrix bob(margaret);
// //     bob.mul_number(5);
// //     // margaret.printer();
// //     S21Matrix c = margaret * bob;
// //     bob.printer();
// //     c.printer();
// //     S21Matrix max((S21Matrix &&) c);
// //     // S21Matrix jei(move(c) );
// //     S21Matrix lui((S21Matrix &)max);
// //     max.printer();
// //     lui.printer();
// //     // printf("\n%d", lui.rows_);
// //     // printf("\n%d", lui.cols_);
// //     if (lui.eq_matrix(max)) {
// //         printf("1111");
// //     } else {
// //         printf("\n no");
// //     }
// //     if (lui == max) {
// //         printf("1111");
// //     } else {
// //         printf("\n no");
// //     }
// //     c.printer();
// //     test();

void test() {
    S21Matrix margaret(5, 5);
    margaret.placeholder();
    margaret.printer();
    S21Matrix bob(margaret);
    bob = bob + margaret + margaret;
    bob.printer();
}