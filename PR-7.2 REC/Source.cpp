#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void Calc(int** a, const int rowCount, const int colCount, int& max, int j);
void Delete(int** a, int rowCount, int i);
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void rowmem(int** a, const int rowCount, const int colCount, int i);
void mincol(int** a, const int rowCount, int i, int j, int& min);

int main()
{
	srand((unsigned)time(NULL));
	int maxmin;
	int k;
	cout << "Input k:";
	cin >> k;
	int n;
	cout << "Input n:";
	cin >> n;
	cout << endl;
	int low = -5;
	int high = 5;
	int** a = new int* [k];
	rowmem(a, k, n, 0);
	Create(a, k, n, low, high, 0, 0);
	Print(a, k, n, 0, 0);
	Calc(a, k, n, maxmin, 1);
	cout << "Maxmin :" << maxmin;
	Delete(a, k, 0);
	delete[] a;
	return 0;
}
void rowmem(int** a, const int rowCount, const int colCount, int i)
{
	a[i] = new int[colCount];
	if (i < rowCount - 1)
		rowmem(a, rowCount, colCount, i + 1);
}
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
}


void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}
void Calc(int** a, const int rowCount, const int colCount, int& max, int j)
{
	int min = a[0][j];
	mincol(a, rowCount, 1, j, min);
		if (j == 1)
			max = min;
		if (min > max)
			max = min;
		if ( j < colCount-1)
			Calc(a, rowCount, colCount, max, j + 2);
}
void mincol(int** a, const int rowCount, int i, int j ,int& min)
{
	if (a[i][j] < min)
		min = a[i][j];
	if (i < rowCount - 1)
		mincol(a, rowCount,i+1,j, min);
}

void Delete(int** a, int rowCount, int i)
{
	delete[] a[i];
	if (i < rowCount - 1)
		Delete(a, rowCount, i + 1);
	return;
}