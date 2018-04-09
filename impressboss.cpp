#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

#define _R1(x) x.begin(), x.end()
#define _R2(x) auto iter = x.begin(); iter != x.end(); ++iter
typedef vector<int> Myvec;
typedef Myvec::iterator Myiter;

// THERE ARE ONLY TWO BOUNDARY CASES, FIND "NOTHING ELSE" IDEA
bool canModify(vector<int> a)				// == the only thing
{
	if (a.size() <= 2) return true;

	Myvec b = a;

	for (int i = 1; i < a.size(); i++)
	{
		if (a[i - 1] > a[i])
		{
			a[i - 1] = (i > 1) ? a[i - 2] : 1;
			b[i] = b[i - 1];
			break;
		}

	}

	if (std::is_sorted(_R1(a))) return true;

	if (std::is_sorted(_R1(b))) return true;

	return false;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		int n;
		cin >> n;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		string a_temp_temp;
		getline(cin, a_temp_temp);

		vector<string> a_temp = split_string(a_temp_temp);

		vector<int> a(n);

		for (int a_itr = 0; a_itr < n; a_itr++) {
			int a_item = stoi(a_temp[a_itr]);

			a[a_itr] = a_item;
		}

		bool result = canModify(a);

		fout << (result ? "YES" : "NO") << "\n";
	}

	fout.close();

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
