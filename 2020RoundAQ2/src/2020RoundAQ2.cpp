//============================================================================
// Name        : 2020RoundAQ2.cpp
// Author      : Okan UYSAL
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int n, k, p;

	cin >> n >> k >> p;
	vector<int> a(p);

	for (int i = 0; i < n; i++) {
		vector<int> b(p);
		int value = 0;
		for (int j = 0; j < k; j++) {
			int temp;
			cin >> temp;
			value += temp;

			if (j < p) {
				b[j] = max(a[j], b[j]);
				b[j] = max(value, b[j]);
			}

			for (int k = 0; j + k + 1 < p; k++) {
				int maxValue = max(a[j + k + 1], a[k] + value);
				b[j + k + 1] = max(maxValue, b[j + k + 1]);
			}
		}
//		for (std::vector<int>::const_iterator y = b.begin(); y != b.end(); ++y)
//		    std::cout << *y << ' ';
//		cout << "\n\n";
		a = b;
	}

	cout << a[p - 1] << '\n';

}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
