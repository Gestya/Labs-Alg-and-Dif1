#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

const int max_value = 100001;

void heapify(int i, int& a, int& b, float mass[]) {
	int maxP = i;
	float maxV = mass[i];
	for (int k = 1; k <= b; k++) {
		int p = b * i + k;
		if (p >= a) {
			break;
		}
		if (mass[p] > maxV) {
			maxV = mass[p];
			maxP = p;
		}
	}
	if (maxP != i) {
		std::swap(mass[i], mass[maxP]);
		heapify(maxP, a, b, mass);
	}
}

void build(int& a, int& b, float mass[]) {
	for (int i = a - 1; i >= 0; i--) {
		heapify(i, a, b, mass);
	}
}

float Exyract_Max(int& a, int& b, float mass[]) {
	float maxV = mass[0];
	std::swap(mass[0], mass[a - 1]);
	a--;
	heapify(0, a, b, mass);
	return maxV;
}

void Increase_Key(int i, float v, int& b, float mass[]) 
{
	if (i == 0) {
		mass[0] = v;
		return;
	}
	int p = (i - 1) / b;
	if (mass[p] < v) 
	{
		mass[i] = mass[p];
		Increase_Key(p, v, b, mass);
	}
	else {
		mass[i] = v;
	}
}

void Insert(float v, int& a, int& b, float mass[]) {
	a++;
	Increase_Key(a - 1, v, b, mass);
}

void print(int& a, float mass[]) 
{
	std::cout << "Heap: ";

	for (int i = 0; i < a; i++) 
		std::cout << mass[i] << " ";

	std::cout << std::endl;
}

int main()
{

	std::ifstream cin("data.txt");


	int a, b;
	float mass[max_value];

	cin >> a >> b;
	if (b < 1) {
		std::cout << "Incorrect d" << std::endl;
		return 0;
	}

	std::cout << "Start array: ";
	for (int i = 0; i < a; i++)
	{
		cin >> mass[i];
		std::cout << mass[i] << " ";
	}

	std::cout << std::endl;

	build(a, b, mass);
	print(a, mass);

	std::string op;

	while (cin >> op) {
		if (op == "inc") {
			int i;
			float v;
			cin >> i >> v;

			Increase_Key(i, v, b, mass);

			std::cout << "Key in position " << i << " increased to " << v << std::endl;
		}

		else if (op == "ex") 
		{
			std::cout << "Extracted max = " << Exyract_Max(a, b, mass) << std::endl;
		}
		else {
			float v;
			cin >> v;
			Insert(v, a, b, mass);
			std::cout << "Inserted element " << v << std::endl;
		}
		print(a, mass);
	}

	return 0;
}