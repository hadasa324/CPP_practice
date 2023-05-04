// C++ code for the above approach

#include <bits/stdc++.h>
using namespace std;

string reverse_words(string s)
{
	int left = 0, i = 0, n = s.size();

	while (s[i] == ' ')
		i++;

	left = i;

	while (i < n) {
		if (i + 1 == n || s[i] == ' ') {
			int j = i - 1;
			if (i + 1 == n)
				j++;

			while (left < j)
				swap(s[left++], s[j--]);

			left = i + 1;
		}
		if (i > left && s[left] == ' ')
			left = i;

		i++;
	}
	reverse(s.begin(), s.end());
	return s;
}

// Driver code
int main()
{

	string str = "i like this program very much";

	str = reverse_words(str);

	cout << str;

	return 0;
}
