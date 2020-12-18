// Lab_7_3_1.cpp
// < Сорочак Станіслав >
// Лабораторна робота № 7.3.1
//Ітераційний спосіб, Завдання 1
// Варіант 24

#include <iostream>
#include <Windows.h>
#include <iomanip>

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
int Sum(int** a, const int rowCount, const int colCount);

int main(void)
{
	srand((unsigned)time(NULL));

	using std::cout;
	using std::endl;

	const int rowCount = 3;
	const int colCount = 3;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	int High = 45;
	int Low = -16;
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);

	int suma = Sum(a, rowCount, colCount);
	cout << "S = " << suma << endl;
	cout << endl;


	delete[] a;

	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	using std::cout;
	using std::endl;
	using std::cin;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}

void Print(int** a, const int rowCount, const int colCount)
{
	using std::cout;
	using std::endl;
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << std::setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int Sum(int** a, const int rowCount, const int colCount)
{
	int sum = 0;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j1 = 0; j1 < colCount; j1++)
		{
			if (a[i][j1] < 0)
			{
				for (int j = 0; j < colCount; j++)
					sum += a[i][j];
				j1 = colCount;
			}
		}
	}
	return sum;
}
