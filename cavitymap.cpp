#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

typedef vector<string> Myvec;
typedef Myvec::iterator Myiter;

#define _R1(x) x.begin(), x.end()
#define _R2(x) auto iter = x.begin(); iter != x.end(); ++iter

struct Cavity
{
	int x;
	int y;
};
typedef vector<Cavity> Cvvec;

Myvec cavityMap(const Myvec& grid)
{
	Myvec ans; Cvvec cvlist;

	const size_t my_size = grid.size();

	if (my_size < 3) return grid;


	vector<vector<int>> matrix (my_size, vector<int>(my_size, 1));

	for (size_t i = 0; i < my_size; i++)
	{
		string temp = grid[i];
		for (size_t j = 0; j < my_size; j++)
		{
			matrix[i][j] = temp[j] - '0';
		}
	}

	// find cavities
	for (size_t i = 1; i < my_size - 1; i++)
	{
		for (size_t j = 1; j < my_size - 1; j++)
		{
			int current = matrix[i][j];
			int left  = matrix[i][j-1];
			int right = matrix[i][j+1];
			int top   = matrix[i-1][j];
			int bottom = matrix[i+1][j];

			if (current <= left) continue;
			if (current <= right) continue;
			if (current <= top) continue;
			if (current <= bottom) continue;

			Cavity temp; temp.x = j; temp.y = i;
			cvlist.push_back(temp);
		}
	}


	// copy grid
	for (size_t i = 0; i < my_size; i++)
	{
		string temp = grid[i];
		ans.push_back(temp);
	}

	// insert cavities
	for (auto iter = cvlist.begin(); iter != cvlist.end(); ++iter)
	{
		string temp = ans[iter->y];
		temp[iter->x] = 'X';
		ans[iter->y] = temp;
	}
	
	return ans;
}

int main() {
	const int n = 4;
	Myvec grid;
	
	grid.push_back("1112");
	grid.push_back("1912");
	grid.push_back("1892");
	grid.push_back("1234");
	
	vector <string> result = cavityMap(grid);

	cout << endl;

	return 0;
}
