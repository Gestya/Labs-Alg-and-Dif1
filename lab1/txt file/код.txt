#include "pch.h"
#include <iostream>
#include <fstream>

//злиття двух масивів
void filtr(int mas[], int mass1[], int mas2[], int leg1, int leg2)
{
	int t = 0, k = 0;

	for (int i = 0; i < leg1 + leg2; i++)
	{
	
		if (t == leg1)
		{
			mas[i] = mas2[k];
				k++;
		}
		else if (k == leg2)
		{
			mas[i] = mass1[t];
			t++;
		}
		else
		{
			if(mass1[t] > mas2[k])
			{
				mas[i] = mas2[k];
				k++;
			}
			else
			{
				mas[i] = mass1[t];
				t++;
			}
		}

	}
}


//розбиття масива на елементи
void sort(int mas[], int leg)
{
	if (leg > 1)
	{
	
		int leg1 = leg / 2, leg2 = 0;

		if (leg % 2 == 0)
			leg2 = leg1;
		else
			leg2 = leg1 + 1;


		int* mass1 = new int[leg1];
		int* mas2 = new int[leg2];

		for (int i = 0; i < leg1; i++)
			mass1[i] = mas[i];
		for (int i = leg1; i < leg; i++)
			mas2[i - leg1] = mas[i];

		sort(mass1, leg1);
		sort(mas2, leg2);

		filtr(mas, mass1, mas2, leg1, leg2);

		delete[] mass1;
		delete[] mas2;
	}
}

int main()
{
	std::ifstream in("Data.txt");

	if (!in.is_open())
	{
		std::cout << "wrong file!";
		return 1;
	}

	//Визначення розміру файла
	int max_l = 0, b = 0;
	while (in >> b)
		max_l++;
	in.close();

	//створення головного масива
	int* mass = new int[max_l];
	b = 0;

	std::ifstream fin("Data.txt");

	//запис масива
	while (fin >> mass[b])
		b++;
	fin.close();



	sort(mass, max_l);
	
	for (int ii = 0; ii < max_l; ii++)
		std::cout << mass[ii] << " ";
	
	delete[] mass;

	return 0;
}