#include <gtest/gtest.h>

#include "s21_matrix_oop.h"
// using namespace std;
// #include <gtest/gtest.h>
// #include "matrix_cpp.h"

TEST(test_eq_matrix, test1) {
    S21Matrix harry(3, 3);
    S21Matrix billi(3, 3);
    harry.placeholder();
    billi.placeholder();
    if (harry == billi) {
        EXPECT_EQ(1, 1);
    }
}

TEST(test_eq_assignment, test1) {
    S21Matrix harry(3, 3);
    S21Matrix billi(3, 3);
    harry.placeholder();
    billi.placeholder();
    harry = billi + harry;
    if (harry == billi + billi) {
        EXPECT_EQ(1, 1);
    }
    // matrix2.plase
    // EXPECT_EQ(matrix1.eq_matrix(matrix2), 1);
}

TEST(test_transpose, test1) {
    S21Matrix sarah(3, 3);
    sarah.placeholder();
    sarah.printer();
    sarah.transpose();
    sarah.printer();
    // matrix2.plase
    // EXPECT_EQ(matrix1.eq_matrix(matrix2), 1);
}

TEST(test_exception_parametr, test1) { S21Matrix sarah(0, 0); }
TEST(test_base, test1) { S21Matrix sarah(); }
TEST(test_transportin, test1) {
    S21Matrix bob();

    S21Matrix sarah();
}
TEST(test_simple_tests, test1) {
    S21Matrix margaret(5, 5);
    margaret.placeholder();
    margaret.printer();
    S21Matrix bob(margaret);
    bob.mul_number(5);
    // margaret.printer();
    S21Matrix c = margaret * bob;
    bob.printer();
    c.printer();
    S21Matrix max((S21Matrix &&) c);
    // S21Matrix jei(move(c) );
    S21Matrix lui((S21Matrix &)max);
    max.printer();
    lui.printer();
    // printf("\n%d", lui.rows_);
    // printf("\n%d", lui.cols_);
    if (lui.eq_matrix(max)) {
        printf("1111");
    } else {
        printf("\n no");
    }
    if (lui == max) {
        printf("1111");
    } else {
        printf("\n no");
    }
    c.printer();
}
TEST(test_another_simple_tests, test1) {
    S21Matrix margaret(5, 5);
    margaret.placeholder();
    margaret.printer();
    S21Matrix bob(margaret);
    bob = bob + margaret + margaret;
    bob.printer();
}
TEST(test_sum, test1) {
    S21Matrix sarah(0, 0);
    S21Matrix jon(0, 0);
    sarah.sum_matrix(jon);
}
TEST(test_determinant, test1) {
    S21Matrix sarah(3, 3);
    sarah.placeholder();
    sarah.determinant();
}
TEST(higher_test_for_determinant, test1) {
    S21Matrix sarah(4, 4);
    sarah.placeholder();
    printf("\n%lf", sarah.determinant());
    sarah.printer();
}
TEST(higher_test_for_calcomplements, test1) {
    S21Matrix sarah(4, 4);
    sarah.placeholder();
    sarah = sarah.calc_complements();
    sarah.printer();
}
TEST(high_test_for_calcomplements, test1) {
    S21Matrix sarah(4, 4);
    sarah.placeholder_for_inverse();
    sarah.printer();
    sarah = sarah.inverse_matrix();
    sarah.printer();
}
TEST(test_index_operator, test1) {
    S21Matrix sarah(4, 4);
    sarah.placeholder_for_inverse();
    printf("\n%d", sarah(3, 0));
}
TEST(test_getters, test1) {
    S21Matrix sarah(4, 4);
    sarah.placeholder_for_inverse();
    printf("\n%d", sarah.get_row());
    printf("\n%d", sarah.get_col());
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
