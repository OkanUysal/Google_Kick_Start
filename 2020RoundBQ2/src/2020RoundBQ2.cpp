//============================================================================
// Name        : 2020RoundBQ2.cpp
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
	int n;
	unsigned long long d;
	cin >> n >> d;

	vector<unsigned long long> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		d = d - (d % a[i]);
	}

	cout << d << "\n";

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
