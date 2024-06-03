#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult

// In defining the test cases, we have used metamorphic relations of matrix multiplication.
// Let A, B, and C be matrices of size m x n, n x p, and m x p, respectively. Then, the following relation holds:
// (aA)B = a(AB) = A(aB) = aAB, where a is a scalar.
// (A^T)(B^T) = (AB)^T
// (-A)(-B) = AB
// A(I) = A
// A(0) = 0
// A(A^(-1)) = I

/**
 * @brief Fist test provided by the assignment.
 *
 */
TEST(MatrixMultiplicationTest, TestMultiplyMatrices)
{
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}};
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {58, 64},
        {139, 154}};

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

/**
 * @brief Test the pre-multiplication by a scalar of the product for the matrices in first test.
 * Starting from the first test and the methamorphic relation that starting from AB = C states aAB = aC with scalar a.
 *
 */
TEST(MatrixMultiplicationTest, TestPremultScalar)
{
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}};
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    for (auto &v : A)
        for (auto &e : v)
            e *= 2;

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {58, 64},
        {139, 154}};

    for (auto &v : expected)
        for (auto &e : v)
            e *= 2;

    ASSERT_EQ(C, expected) << "Multiplication with scalar test failed! :(((()";
}

/**
 * @brief Test the multiplication of a squared matrix by itself.
 *
 */
/*TEST(MatrixMultiplicationTest, TestSquareByItself)
{
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, A, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {30, 36, 42},
        {66, 81, 96},
        {102, 126, 150}};

    ASSERT_EQ(C, expected) << "Square matrix by itself test failed! :(((()";
}*/

/**
 * @brief Test the transpose commutativity property (B^T*A^T) = (A*B)^T.
 * Starting from the given test and the metamorphic relation (B^T*A^T) = (A*B)^T
 * this test can be defined as (B^T*A^T) = (A*B)^T = C^T
 *
 */
TEST(MatrixMultiplicationTest, TestTranspose)
{
    std::vector<std::vector<int>> AT = {
        {1, 4},
        {2, 5},
        {3, 6}};
    std::vector<std::vector<int>> BT = {
        {7, 9, 11},
        {8, 10, 12}};
    std::vector<std::vector<int>> CT(2, std::vector<int>(2, 0));

    multiplyMatrices(BT, AT, CT, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {58, 139},
        {64, 154}};

    ASSERT_EQ(CT, expected) << "Matrix transpose test failed! :(((()";
}

/**
 * @brief Test the multiplication by two matrices with same values.
 *
 */
/*TEST(MatrixMultiplicationTest, TestSameValues)
{
    std::vector<std::vector<int>> A = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};

    std::vector<std::vector<int>> B = {
        {33, 33, 33},
        {33, 33, 33},
        {33, 33, 33}};

    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {99, 99, 99},
        {99, 99, 99},
        {99, 99, 99}};

    ASSERT_EQ(C, expected) << "Square matrix by itself test failed! :(((()";
}*/

/**
 * @brief Test with negative matrices.
 * From the first test, and from the meta relation (-A)*(-B)=C we can test this
 *
 */
TEST(MatrixMultiplicationTest, TestNegativeMatrices)
{
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}};
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    for (auto &v : A)
        for (auto &e : v)
            e *= -1;

    for (auto &v : B)
        for (auto &e : v)
            e *= -1;

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {58, 64},
        {139, 154}};

    ASSERT_EQ(C, expected) << "Matrix negative test failed! :(((()";
}

/**
 * @brief Test with same value in a row and column
 *
 */
/*TEST(MatrixMultiplicationTest, TestSameRowCol)
{
    std::vector<std::vector<int>> A = {
        {1, 2, 2},
        {1, 2, 6}};
    std::vector<std::vector<int>> B = {
        {1, 1},
        {2, 2},
        {2, 2}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));


    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {9, 9},
        {17, 17}};

    ASSERT_EQ(C, expected) << "Matrix negative test failed! :(((()";
}*/

/**
 * @brief Test according to the meta relation A*I = A
*/
TEST(MatrixMultiplicationTest, TestIdentityMatrix)
{
     std::vector<std::vector<int>> A = {
        {1, 1, 2},
        {3, 3, 4},
        {5, 5, 5}};

    std::vector<std::vector<int>> B = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};

    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    ASSERT_EQ(C, A) << "Identity matrix test failed! :(((()";
}

/**
 * @brief Test according to the meta relation A*0 = 0
*/
TEST(MatrixMultiplicationTest, TestZeroMatrix)
{
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    std::vector<std::vector<int>> B = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};

    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    ASSERT_EQ(C, B) << "Zero matrix test failed! :(((()";
}

/**
 * @brief Test according to the meta relation A*A^(-1) = I
 * 
 */
TEST(MatrixMultiplicationTest, TestInverseMatrix)
{
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 7},
        {8, 9, 12}};

    std::vector<std::vector<int>> B = {
        {-3, 3, -1},
        {8, -12, 5},
        {-4, 7, -3}};

    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};

    ASSERT_EQ(C, expected) << "Square matrix by itself test failed! :(((()";
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}