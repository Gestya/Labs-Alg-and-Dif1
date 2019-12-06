#include <conio.h>
#include <iostream>
#include <unordered_map>
#include <iostream>

class NutsAndBoltsMatch
{
private:
	 /*Printing the resulting array.
	 in: an array of numbers and their length.*/
	static void printArray(int array[], int n) {
		for (int i = 0; i < n; i++)
			std::cout << array[i] << " ";
		std::cout << std::endl;
	};

	/*Matching two values to the other until the same pair is established.
	in: In the first case, obtain the value of one bolt and array of nuts, and the maximum and minimum values of the range, to establish the appropriate pair.
	in:In other cases we get one nut value and an array of bolts.
	return:the value of the object that will need to be worked on in the next step.*/
	static int partition(int arr[], int pivot,  int low, int high) 
	{

		int pi = low;
		for (; low < high; low++)
		{
			if (arr[low] < pivot)
			{
				std::swap(arr[pi], arr[low]);
				pi++;
			}
			else if (arr[low] == pivot)
			{
				std::swap(arr[low], arr[high]);
				low--;
			}
		}
		std::swap(arr[pi], arr[high]);
		return pi;
	};

	/*Invokes the pair search function by giving them the correct values.
	In: array of nuts and bolts, with lower and upper search range.*/
	static void matchPairs(int nuts[], int bolts[], int low, int high) {
		if (low < high)
		{
			int pivot = partition(nuts, bolts[high], low, high);
			partition(bolts, nuts[pivot], low, high);

			matchPairs(nuts, bolts, low, pivot - 1);
			matchPairs(nuts, bolts, pivot + 1, high);
		}
	};
public:

	/*Invokes pair matching and array printing functions.
	in: array of bolts, nuts and their length values.*/
	static void PartitionMatch(int nuts[], int bolts[], int n) 
	{
		matchPairs(nuts, bolts, 0, n - 1);

		std::cout << "Matched nuts and bolts are : \n";

		printArray(nuts, n);
		printArray(bolts, n);
	}
};

int main()
{
	NutsAndBoltsMatch test;

	int nuts[] = { 13, 67, 42, 2, 24, 1 };
	int bolts[] = { 42, 2, 1, 24, 13, 67 };


	test.PartitionMatch(nuts, bolts, sizeof(nuts) / sizeof(nuts[0]));

	return 0;
}