#include<iostream>
#include <conio.h>


void function(int mass[], int size)
{
	int negative = 0;

	for (int i = 0; i < size; i++)
		if (mass[i] < 0)
			negative++;

	for (int i = 0, j = 1; i != negative;)
	{

		if (mass[i] < 0) 
		{
			i++;
			j = i + 1;
		}


		else if (mass[i] > 0 && j < size)
		{
			std::swap(mass[i], mass[j]);
			j++;
		}
	}
}

int main()
{
	int count_negative = 0;

	int mass[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6 };
	int size = sizeof(mass) / sizeof(mass[0]);
	function(mass, size);

	for (int i = 0; i < size; i++)
		std::cout << mass[i] << " ";

	std::cout << std::endl;

	return 0;
}

