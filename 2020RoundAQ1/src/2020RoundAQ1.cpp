//============================================================================
// Name        : 2020RoundAQ1.cpp
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
	int n, x, amount = 0, count = 0;
	cin >> n >> x;
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++) {
		if (amount + a[i] > x) {
			break;
		}
		amount += a[i];
		count++;

	}

	cout << count << '\n';

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
