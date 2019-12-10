#include <iostream>
#include <conio.h>
#include <string>

void pow(int n, int mass[]);
void has(std::string x_str, int* second, int mass[]);
bool check(int first, int second, std::string first_str, std::string second_str);


int main() {

	std::string first_srt;
	std::string second_str;

	std::cout << "Write of a: ";
	std::cin >> first_srt;

	std::cout << "write of b: ";  
	std::cin >> second_str;

	if (first_srt.size() != second_str.size())
	{
		std::cout << std::endl << "fail";
	
	}
	else
	{

		int maas[100];
		int mass_first[100];
		int mass_second[100];

		int n = first_srt.size();
		first_srt += first_srt;


		pow(2 * n, maas);
		has(first_srt, mass_first, maas);
		has(second_str, mass_second, maas);
		for (int l = 0; l < n - 1; l++)
		{
			int r = l + n - 1;
			if (mass_first[r] - (l ? mass_first[l - 1] : 0) == mass_second[n - 1] * maas[l] && check(l, r, first_srt, second_str)) 
			{
				std::cout << std::endl << "correct!";
				return 0;
			}
		}
		std::cout << std::endl << "fail";

	}

	return 404;
}

void pow(int x, int mass[])
{
	mass[0] = 1;
	for (int i = 1; i < x; i++)
		mass[i] = mass[i - 1] * 31;
}

void has(std::string x_str, int* number, int power[])
{
	number[0] = x_str[0];
	for (int i = 1; i < x_str.size(); i++)
	{
		power[i] = power[i - 1] * 31;
		number[i] = number[i - 1] + x_str[i] * power[i];
	}
}

bool check(int first, int second, std::string first_str, std::string swcond_str)
{
	for (int i = first; i <= second; i++)
		if (first_str[i] != swcond_str[i - first])
			return false;
	return true;
}