#include <iostream>
#include <time.h>
#include "../include/main.h"

using namespace std;

int main()
{
  srand((unsigned)time(NULL));

  int Low = -6;
  int High = 31;
  int rowCount = 7;
  int colCount = 5;

  int **r = new int*[rowCount];
  Init(r, rowCount, colCount, 0);

  Create(r, rowCount, colCount, Low, High, 0, 0);
  Print(r, rowCount, colCount, 0, 0);
  cout << endl;
  Sort(r, rowCount, colCount, 0, 0);
  Print(r, rowCount, colCount, 0, 0);

  int S=0;
  int k=0;

  Calc(r, rowCount, colCount, S, k, 0, 0);

  cout << endl << "S = " << S << endl;
  cout << "k = " << k << endl << endl;
  Print(r, rowCount, colCount, 0, 0);

  Delete(r, rowCount, 0);
  delete [] r;

  return 0;
}