#include <iostream>
using namespace std;

void FillRand(int** arr, const int rows, const int cols);
void Print(int** arr,  const int rows,  const int cols);
int** push_row_back(int** arr,  int &rows, const int cols);
int** push_row_front(int  );
int** insert_row();
int** pop_row_back();
int** pop_row_front();


void main() 
{
	setlocale(LC_ALL, "");
	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete arr;
}

void FillRand(int** arr,  const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int** arr,  const int rows,  const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j]<< "\t";
		}
		cout << endl;
	}
}

int** push_row_back(int** arr,  int &rows,  const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i]=arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[rows] = new int[cols];
	rows++;
	return arr;
}
