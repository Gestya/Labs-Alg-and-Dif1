#include <iostream>
#include <string>
#include <conio.h>

const int max_size = 100;



bool trivialCheck(int t, int q, int l, int r);
bool check(int t, int q, int l, int r, int n, int power[]);


void calculatePowers(int n, int power[]) 
{
	power[0] = 1;
	for (int i = 1; i < n; i++)
		power[i] = power[i - 1] * 31;
}


int ha[max_size][max_size];
int hb[max_size][max_size];

void makeHash(std::string s, int* h, int power[]) 
{
	h[0] = s[0];
	for (int i = 1; i < s.size(); i++) 
	{
		power[i] = power[i - 1] * 31;
		h[i] = h[i - 1] + s[i] * power[i];
	}
}



int main() {

	int m, n;
	std::cout << "Enter the size of text m: ";
	std::cin >> m;
	std::cout << std::endl << "And size of substr n: ";
	std::cin >> n;

	if (m < n) 
	{
		std::cout << "no result";
	}
	else
	{
		int power[max_size];

		calculatePowers(m, power);

		std::string a[max_size];
		std::string b[max_size];

		for (int i = 0; i < m; i++)
		{
			std::cout << std::endl << "Write your " << i + 1 << "/" << m << " elmnet for m: ";
			std::cin >> a[i];
			makeHash(a[i], ha[i], power);
		}
		for (int i = 0; i < n; i++)
		{
			std::cout << std::endl << "Write your " << i + 1 << "/" << n << " elmnet for n: ";
			std::cin >> b[i];
			makeHash(b[i], hb[i], power);
		}

		std::cout << std::endl << "in result: ";

		for (int i = 0; i < m - n + 1; i++)
			for (int j = 0; j < m - n + 1; j++)
				for (int k = i; k < i + n; k++)
					if (!check(i, k, j, j + n - 1, n, power))
						std::cout << std::endl << " [" << i << ", " << j << "]" ;
	}
	
	
	return 404;
}

bool check(int t, int q, int l, int r, int n, int power[])
{
	if (ha[q][r] - (l ? ha[q][l - 1] : 0) != hb[q - t][n - 1] * power[l])
		return false;

	else if (trivialCheck(t, q, l, r))
		return true;

	return false;
}

bool trivialCheck(int t, int q, int l, int r)
{
	for (int i = l; i <= r; i++)
		if (ha[q][i] != hb[q - t][i - l])
			return false;

	return true;
}