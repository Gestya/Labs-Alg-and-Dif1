#include <iostream>
#include <conio.h>

const int max_value = 4;


void co(int n, int C[][max_value]);
void sum(int A[][max_value], int B[][max_value], int C[][max_value]);
void add(int n, int X[][max_value], int Y[][max_value], int Z[][max_value]);
void sumB(int n, int X[][max_value], int Y[][max_value], int Z[][max_value]);
void general(int n, int A[][max_value], int B[][max_value], int C[][max_value]);


int main() 
{
	int A[max_value][max_value] = {
		{ 5, 6, 2, 8 },
		{ 6, 1, 9, 5 },
		{ 4, 5, 6, 5 },
		{ 7, 8, 9, 7 }
	};

	int B[max_value][max_value] = {
		{ 4, 5, 6, 5 },
		{ 7, 8, 9, 7 },
		{ 7, 3, 8, 2 },
		{ 1, 2, 9, 1 }
	};

	int C[max_value][max_value];

	co(max_value, A);
	co(max_value, B);

	general(max_value, A, B, C);

	co(max_value, C);

	return 0;
}





void co(int n, int C[][max_value])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			std::cout << C[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


void sum(int A[][max_value], int B[][max_value], int C[][max_value])
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			C[i][j] = 0;
			for (int t = 0; t < 2; t++)
				C[i][j] = C[i][j] + A[i][t] * B[t][j];
		}
}

void add(int n, int X[][max_value], int Y[][max_value], int Z[][max_value])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			Z[i][j] = X[i][j] + Y[i][j];
}

void sumB(int n, int X[][max_value], int Y[][max_value], int Z[][max_value])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			Z[i][j] = X[i][j] - Y[i][j];
}


void general(int n, int A[][max_value], int B[][max_value], int C[][max_value]) 
{
	int A11[max_value][max_value];
	int A12[max_value][max_value];
	int A21[max_value][max_value];
	int A22[max_value][max_value];
	int B11[max_value][max_value];
	int B12[max_value][max_value];
	int B21[max_value][max_value];
	int B22[max_value][max_value];
	int C11[max_value][max_value];
	int C12[max_value][max_value];
	int C21[max_value][max_value];
	int C22[max_value][max_value];
	int M1[max_value][max_value];
	int M2[max_value][max_value];
	int M3[max_value][max_value];
	int M4[max_value][max_value];
	int M5[max_value][max_value];
	int M6[max_value][max_value];
	int M7[max_value][max_value];
	int AA[max_value][max_value];
	int BB[max_value][max_value];

	if (n == 2)
	{
		sum(A, B, C);
	}
	else
	{
		for (int i = 0; i < n / 2; i++) 
			for (int j = 0; j < n / 2; j++) 
			{
				A11[i][j] = A[i][j];
				A12[i][j] = A[i][j + n / 2];
				A21[i][j] = A[i + n / 2][j];
				A22[i][j] = A[i + n / 2][j + n / 2];

				B11[i][j] = B[i][j];
				B12[i][j] = B[i][j + n / 2];
				B21[i][j] = B[i + n / 2][j];
				B22[i][j] = B[i + n / 2][j + n / 2];
			}

		add(n / 2, A11, A22, AA);
		add(n / 2, B11, B22, BB);
		general(n / 2, AA, BB, M1);

		add(n / 2, A21, A22, AA);
		general(n / 2, AA, B11, M2);

		sumB(n / 2, B12, B22, BB);
		general(n / 2, A11, BB, M3);


		sumB(n / 2, B21, B11, BB);
		general(n / 2, A22, BB, M4);

		add(n / 2, A11, A12, AA);
		general(n / 2, AA, B22, M5);


		sumB(n / 2, A21, A11, AA);
		add(n / 2, B11, B12, BB);
		general(n / 2, AA, BB, M6);

		sumB(n / 2, A12, A22, AA);
		add(n / 2, B21, B22, BB);
		general(n / 2, AA, BB, M7);

		add(n / 2, M1, M4, AA);
		sumB(n / 2, M7, M5, BB);
		add(n / 2, AA, BB, C11);

		add(n / 2, M3, M5, C12);

		add(n / 2, M2, M4, C21);

		sumB(n / 2, M1, M2, AA);
		add(n / 2, M3, M6, BB);
		add(n / 2, AA, BB, C22);

		for (int i = 0; i < n / 2; i++)
			for (int j = 0; j < n / 2; j++)
			{
				C[i][j] = C11[i][j];
				C[i][j + n / 2] = C12[i][j];
				C[i + n / 2][j] = C21[i][j];
				C[i + n / 2][j + n / 2] = C22[i][j];
			}
	}
}