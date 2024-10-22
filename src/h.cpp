#include "../include/main.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Init (int** a, int rowCount, int colCount, int i) {
  if (i < rowCount) {
    a[i] = new int[colCount];
    Init(a, rowCount, colCount, i+1);
  }
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
  a[i][j] = Low + rand() % (High-Low+1);

  if (i < rowCount - 1) {
    Create(a, rowCount, colCount, Low, High, i+1, j);
    if (j < colCount - 1)
      Create(a, rowCount, colCount, Low, High, i, j+1);
  }
}
void Print (int** a, const int rowCount, const int colCount, int i, int j)
{
  cout << setw(4) << a[i][j];

  if (j < colCount - 1)
    Print(a, rowCount, colCount, i, j+1);
  else if (i < rowCount - 1)
  {
    cout << endl;
    Print(a, rowCount, colCount, i+1, 0);
  }
  else
    cout << endl;
}

void Sort(int** a, const int rowCount, const int colCount, int j0, int j1)
{
  if (j0 < colCount - 1)
  {
    if (j1 < colCount - j0 - 1)
    {
      if (( a[0][j1] > a[0][j1+1] )
        ||
        ( a[0][j1] == a[0][j1+1] &&
        a[1][j1] > a[1][j1+1] )
        ||
        ( a[0][j1] == a[0][j1+1] &&
        a[1][j1] == a[1][j1+1] &&
        a[2][j1] < a[2][j1+1] ))
        Change(a, j1, j1+1, rowCount, 0);
      Sort(a, rowCount, colCount, j0, j1+1);
    }
    Sort(a, rowCount, colCount, j0+1, 0);
  }
}

void Change(int** a, const int col1, const int col2, const int rowCount, int i) {
  if (i < rowCount) {
    int tmp = a[i][col1];
    a[i][col1] = a[i][col2];
    a[i][col2] = tmp;
    Change(a, col1, col2, rowCount, i+1);
  }
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
  if (i < rowCount)
  {
    if (j < colCount)
    {
      if (a[i][j] > 0 && !(i % 3 == 0 || j % 3 == 0))
      {
        S += a[i][j];
        k++;
        a[i][j] = 0;
      }
      Calc(a, rowCount, colCount, S, k, i, j+1);
    }
    Calc(a, rowCount, colCount, S, k, i+1, 0);
  }
}

void Delete(int** a, int rowCount, int i) {
  if (i < rowCount) {
    delete [] a[i];
    Delete(a, rowCount, i+1);
  }
}