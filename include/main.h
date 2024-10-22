#ifndef MAIN_H
#define MAIN_H

void Init(int** a, int rowCount, int colCount, int i);
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void Sort(int** a, const int rowCount, const int colCount, int j0, int j1);
void Change(int** a, const int row1, const int row2, const int colCount, int i);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j);
void Delete(int** a, const int rowCount, int i);

#endif //MAIN_H
