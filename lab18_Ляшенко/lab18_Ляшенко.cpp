#include <iostream>
#include <string>
#include "windows.h"
using namespace std;

class matrix
{
public:
	int mat[2][3],m,n,comp = 0;

	void fill()
	{
		for (int i = 0; i < 2; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				cin >> mat[i][k];
			}
		}
	}

	void get()
	{
		for (int i = 0; i < 2; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				cout <<  mat[i][k] << " ";
			}
			cout << endl;
		}
	}

	matrix operator+(matrix op2);
	matrix operator-(matrix op2);
	matrix operator==(matrix op2);
};

matrix matrix::operator+(matrix op2)
{
	matrix sum;
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			sum.mat[i][k] = op2.mat[i][k] + mat[i][k];
		}
	}
	return sum;
}

matrix matrix::operator-(matrix op2)
{
	matrix diff;
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			diff.mat[i][k] = mat[i][k] - op2.mat[i][k];
		}
	}
	return diff;
}

matrix matrix::operator==(matrix op2)
{
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (op2.mat[i][k] != mat[i][k])
			{
				comp++;
			}
		}
	}
	return op2;
}


int main()
{
	matrix m1,m2;
	cout << "Fill matrix m1:" << endl;
	m1.fill();
	cout << endl << "Fill matrix m2:" << endl;
	m2.fill();


	m1 = m1 + m2;
	cout << endl << "m1 = m1 + m2:" << endl;
	m1.get();

	m1 = m1 - m2;
	cout << endl << "m1 = m1 - m2:" << endl;
	m1.get();

	m1 = m1 == m2;
	cout << endl <<"Comparison of m1 and m2:" << endl;
	if (m1.comp == 0)
	{
		cout << "Matrices m1 and m2 are the same." << endl;
	}
	else
	{
		cout << "Matrices m1 and m2 aren't the same." << endl;
	}
}