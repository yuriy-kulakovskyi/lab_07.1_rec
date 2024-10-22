#include <gtest/gtest.h>
#include "../include/main.h"

TEST(CalcTest, HandlesPositiveValues) {
  const int rowCount = 3;
  const int colCount = 3;
  int** a = new int*[rowCount];
  a[0] = new int[colCount]{1, 2, 3};
  a[1] = new int[colCount]{4, 5, 6};
  a[2] = new int[colCount]{7, 8, 9};

  int S = 0;
  int k = 0;

  Calc(a, rowCount, colCount, S, k, 0, 0);

  EXPECT_EQ(S, 28);
  EXPECT_EQ(k, 4);
  EXPECT_EQ(a[1][1], 0);

  delete[] a[0];
  delete[] a[1];
  delete[] a[2];
  delete[] a;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}