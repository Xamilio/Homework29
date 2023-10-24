#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
//int* addstr(int* mas, int sizen, int sizem, int newcolumn)
//{
//	int* res = new int [sizen * (sizem + 1)];
//	for (int i = 0; i < newcolumn * sizem; i++)
//	{
//		 res[i] = mas[i];
//	}
//	for (int i = newcolumn * sizem; i < sizen * sizem; i++)
//	{
//		res[i + sizem] = mas[i];
//	}
//	return res;
//}
//

//1
//int* addcolumn(int* mas, int sizen, int sizem, int newcolumn)
//{
//	
//	int* res = new int[sizen * (sizem + 1)];
//	for (int i = 0; i < sizen; i++)
//	{
//		for (int j = 0; j < newcolumn; j++)
//		{
//			res[i * sizem + j] = mas[i * sizem + j];
//		}
//	}
//
//	for (int i = 0; i < sizen; i++)
//	{
//		for (int j = newcolumn; j < sizem; j++)
//		{
//			res[i * sizem + j + 1] = mas[i * sizem + j];
//		}
//	}
//	return res;
//}
//
//int main()
//{
//	const int size1 = 5;
//	const int size2 = 4;
//	int st = 0;
//	cout << "Введите номер столбца куда вы хотите его добавить: ";
//	cin >> st;
//	int M[size1][size2] =
//	{
//		{0, 0, 0, 0},
//		{0, 0, 0, 0},
//		{0, 0, 0, 0},
//		{0, 0, 0, 0},
//		{0, 0, 0, 0}
//	};
//	int* x = addcolumn(*M, size1, size2, st);
//	for (int i = 0; i < size1; i++)
//	{
//		cout << "\n";
//		for (int j = 0; j < size2 + 1; j++)
//		{
//			cout << x[i * size2 + j] << " ";
//		}
//	}
//}

//2
//int* delcolumn(int* mas, int sizen, int sizem, int column)
//{
//
//	int* res = new int[sizen * (sizem - 1)];
//	for (int i = 0; i < sizen; i++)
//	{
//		for (int j = 0; j < column; j++)
//		{
//			res[i * sizem + j] = mas[i * sizem + j];
//		}
//	}
//
//	for (int i = 0; i < sizen; i++)
//	{
//		for (int j = column; j < sizem - 1; j++)
//		{
//			res[i * sizem + j] = mas[i * sizem + j + 1];
//		}
//	}
//	return res;
//}
//int main()
//{
//	const int size1 = 5;
//	const int size2 = 4;
//	int st = 0;
//	cout << "Введите номер столбца куда вы хотите его добавить: ";
//	cin >> st;
//	int M[size1][size2] =
//	{
//		{1, 2, 3, 4},
//		{1, 2, 3, 4},
//		{1, 2, 3, 4},
//		{1, 2, 3, 4},
//		{1, 2, 3, 4}
//	};
//	int* x = delcolumn(*M, size1, size2, st);
//	for (int i = 0; i < size1; i++)
//	{
//		cout << "\n";
//		for (int j = 0; j < size2 - 1; j++)
//		{
//			cout << x[i * size2 + j] << " ";
//		}
//	}
//}

//3
int* copy(int* mas, int sizen, int sizem, int dn, int dm)
{

	int* res = new int[sizen * sizem];
	for (int i = 0; i < sizen; i++)
	{
		int ni = (i + dn) % sizen;
		if (ni < 0)
		{
			ni = sizen + ni;
		}
		for (int j = 0; j < sizem; j++)
		{
			int nj =  (j + dm) % sizem;
			if (nj < 0)
			{
				nj = nj + sizem;
			}
			int ncar = sizem * ni + nj;
			int car = sizem * i + j;
			res[ncar] = mas[car];
		}
	}
	return res;
}
int main()
{
	const int size1 = 5;
	const int size2 = 4;
	int st1 = 0;
	int st2 = 0;
	cout << "Введите количество раз смещения строки(+ вниз, - вверх): ";
	cin >> st1;
	cout << "Введите количество раз смещения cтолбец(+ вправо, - влево): ";
	cin >> st2;
	int M[size1][size2] =
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16},
		{17, 18, 19, 20}
	};
	int* x = copy(*M, size1, size2, st1, st2);
	for (int i = 0; i < size1; i++)
	{
		cout << "\n";
		for (int j = 0; j < size2; j++)
		{
			cout << x[i * size2 + j] << " ";
		}
	}
}