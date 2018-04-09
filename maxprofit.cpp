// MaxProfit.cpp

#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;

typedef vector<int> Myvec;
typedef set<int> Myset;

#define LL long long
#define _OS(x) ostream_iterator<x>(cout, " ")
#define _CR cout << endl
#define _R1(x) x.begin(), x.end()
#define _R2(x) auto iter = x.begin(); iter != x.end(); ++iter
#define PRN(x) cout << x << endl
#define PRV(x) copy(_R1(x), _OS(int)); _CR

void find_right_max(const Myvec& orig, Myvec& right_max)
{
	int local_max = INT_MIN;

	for (size_t i = orig.size() - 1; i >= 1; i--)
	{
		if (orig[i] > local_max)
			local_max = orig[i];

		right_max[i - 1] = local_max;
	}
}

// use range tree vs set?
LL maxProfit(const Myvec& a)
{
	LL max_profit = LLONG_MIN;

	if (a.size() < 3) return -1;

	// find right maximum for each [i, n-2]
	Myvec right_max(a.size(), INT_MIN);
	find_right_max(a, right_max);

	bool wasfound = false;

	Myset left_set; left_set.insert(a[0]);
	for (size_t i = 1; i < a.size() - 1; i++)
	{
		// find max left number and multiply by middle one
		auto iter = lower_bound(_R1(left_set), a[i]);
		if (iter != left_set.begin())
			--iter;
		else if (*iter >= a[i])
		{
			left_set.insert(a[i]);
			continue;
		}

		// continue w/ left_set
		left_set.insert(a[i]);

		if (iter == left_set.end()) continue;

		if (a[i] >= right_max[i]) continue;

		wasfound = true;
		LL left_num = *iter;
		left_num *= a[i];
		left_num *= right_max[i];

		if (left_num > max_profit) max_profit = left_num;
	}

	if (wasfound)
		return max_profit;
	else
		return -1;
}

int main()
{
	Myvec aa{ 10, 2, -10, 6, 1, 0, 8 };

	cout << maxProfit(aa) << endl;

	return 0;
}

