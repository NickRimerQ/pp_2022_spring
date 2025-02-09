// Copyright 2022 Kamenev Ilya

#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "./strassen_matrix_multiply.h"

TEST(Kamenev_Strassen_Seq, MatrixSize8Test) {
  int size = 8;
  std::vector<double> a(size * size);
  std::vector<double> b(size * size);
  std::vector<double> strassen_res(size * size);
  std::vector<double> naive_res(size * size);

  for (int i = 0; i < size * size; i++) {
    a[i] = i + 1;
    b[i] = size * size - i;
  }
  strassen(a.data(), b.data(), strassen_res.data(), size);
  naive_mult(a.data(), b.data(), naive_res.data(), size);
  ASSERT_EQ(naive_res, strassen_res);
}

TEST(Kamenev_Strassen_Seq, MatrixSize128Test) {
  int size = 128;
  std::vector<double> a(size * size);
  std::vector<double> b(size * size);
  std::vector<double> strassen_res(size * size);
  std::vector<double> naive_res(size * size);

  for (size_t i = 0; i < size * size; i++) {
    a[i] = i + 1;
    b[i] = size * size - i;
  }
  strassen(a.data(), b.data(), strassen_res.data(), size);
  naive_mult(a.data(), b.data(), naive_res.data(), size);
  ASSERT_EQ(naive_res, strassen_res);
}

TEST(Kamenev_Strassen_Seq, MatrixSize256Test) {
  int size = 256;
  std::vector<double> a(size * size);
  std::vector<double> b(size * size);
  std::vector<double> strassen_res(size * size);
  std::vector<double> naive_res(size * size);

  for (size_t i = 0; i < size * size; i++) {
    a[i] = i + 1;
    b[i] = size * size - i;
  }
  strassen(a.data(), b.data(), strassen_res.data(), size);
  naive_mult(a.data(), b.data(), naive_res.data(), size);
  ASSERT_EQ(naive_res, strassen_res);
}

TEST(Kamenev_Strassen_Seq, MatrixSize64Test) {
  int size = 64;
  std::vector<double> a(size * size);
  std::vector<double> b(size * size);
  std::vector<double> strassen_res(size * size);
  std::vector<double> naive_res(size * size);
  for (size_t i = 0; i < size * size; i++) {
    a[i] = i + 1;
    b[i] = size * size - i;
  }
  strassen(a.data(), b.data(), strassen_res.data(), size);
  naive_mult(a.data(), b.data(), naive_res.data(), size);
  ASSERT_EQ(naive_res, strassen_res);
}

TEST(Kamenev_Strassen_Seq, InvalidSizeTest) {
  int size = 57;
  std::vector<double> a(size * size);
  std::vector<double> b(size * size);
  std::vector<double> strassen_res(size * size);

  for (size_t i = 0; i < size * size; i++) {
    a[i] = i + 1;
    b[i] = size * size - i;
  }
  ASSERT_THROW(strassen(a.data(), b.data(), strassen_res.data(), size),
               std::invalid_argument);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
