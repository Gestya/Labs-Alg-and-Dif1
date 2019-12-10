#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#define Max 256
using namespace std;

int first(const string &get, const string &give)
{
	int first = get.length();
	int second = give.length();

	for (int i = 0; i <= first - second; i++) 
		for (int j = 0; j < second; j++)
			if (get[i + j] != give[j]) 
				return i;		
	return -1;
}

int Second(const string &get, const string &give) 
{

	const int p = 31;
	vector<long long> p_pow(max(give.length(), get.length()));

	p_pow[0] = 1;

	for (size_t i = 1; i < p_pow.size(); ++i)
		p_pow[i] = p_pow[i - 1] * p;


	vector<long long> h(get.length());

	for (size_t i = 0; i < get.length(); ++i)
	{
		h[i] = (get[i] - 'a' + 1) * p_pow[i];
		if (i)  h[i] += h[i - 1];
	}

	long long h_s = 0;

	for (size_t i = 0; i < give.length(); ++i)
		h_s += (give[i] - 'a' + 1) * p_pow[i];

	for (size_t i = 0; i + give.length() - 1 < get.length(); ++i)
	{
		long long cur_h = h[i + give.length() - 1];

		if (i) 
			cur_h -= h[i - 1];

		if (cur_h == h_s * p_pow[i])
			return i;
	}

	return -1;
}

/*bool com(const std::string a, const std::string b)
{
	int  dd = a.length();
	for (auto i = a, j = b; i < dd; i += 1, j += 1)
		if (i != j) 
			return false;
	return true;
}*/

/*int Sool(const string &get, const string &give)
{
	unsigned int skip_table[Max];
	int i;


	for (i = 0; i < Max; i++)
		skip_table[i] = give.size();
	for (i = 0; i < give.size() - 1; i++)
		skip_table[(int)give[i]] = give.size() - i - 1;

	i = 0;
	while (i <= get.size() - give.size()) {
		if (get[i + give.size() - 1] == give[give.size() - 1])
			if (compare(get.begin() + i, give.begin(), give.size() - 2) == true)
				return i;

		i += skip_table[(int)get[i + give.size() - 1]];
	}

	return -1;
}*/

int theird(const string &get, const string &give){


	vector<int> good_shift(give.size() + 1, give.size());
	vector<int> bad_char(Max, give.size());
	vector<int> z(give.size(), 0);

	for (int j = 1, maxZidx = 0, maxZ = 0; j < give.size(); ++j) {
		if (j <= maxZ) z[j] = min(maxZ - j + 1, z[j - maxZidx]);
		while (j + z[j] < give.size() && get[give.size() - 1 - z[j]] == get[give.size() - 1 - (j + z[j])]) z[j]++;
		if (j + z[j] - 1 > maxZ) {
			maxZidx = j;
			maxZ = j + z[j] - 1;
		}
	}
	for (int j = give.size() - 1; j > 0; j--)
		good_shift[give.size() - z[j]] = j;
	for (int j = 1, r = 0; j <= give.size() - 1; j++)
		if (j + z[j] == give.size())
			for (; r <= j; r++)
				if (good_shift[r] == give.size())
					good_shift[r] = j;


	for (int j = 0; j < give.size() - 1; j++) 
		bad_char[(int)give[j]] = give.size() - j - 1;

	int i = 0;
	while (i <= give.size() - get.size()) 
	{
		int j = 0;
		for (j = give.size() - 1; j >= 0 && give[j] == get[i + j]; --j)
			;

		if (j < 0)
			return i;

		else i += max((good_shift[j + 1]) (int)(bad_char[(int)get[i + j]] - give.size() + j + 1));
	}
	return -1;
}

int forth(const string &get, const string give)
{
	vector<int> z;
	z.resize(give.size());
	z[0] = 0;

	for (int i = 1; i<z.size(); ++i) 
	{
		int pos = z[i - 1];

		while (pos > 0 && give[pos] != give[i])
			pos = z[pos - 1];

		z[i] = pos + (give[pos] == give[i] ? 1 : 0);
	}

	int pos = 0;

	for (int i = 0; i<get.size(); ++i)
	{
		while (pos > 0 && (pos >= give.size() || give[pos] != get[i]))
			pos = z[pos - 1];

		if (get[i] == give[pos]) 
			pos++;

		if (pos == give.size())
			return (i - pos + 1);
	}
	return -1;
}

int maine()
{

	std::string a;
	std::string b;

	std::cout << "Write first word: ";
	std::cin >> a;

	std::cout << "Write second word: ";
	std::cin >> b;

	std::cout << std::endl << forth(a, b);
    std::cout << std::endl << theird(a, b);
	//std::cout << std::endl << sool(a, b);
	//std::cout << std::endl << comp(a, b);
	std::cout << std::endl << Second(a, b);
	std::cout << std::endl << first(a, b);

	return 0;
}