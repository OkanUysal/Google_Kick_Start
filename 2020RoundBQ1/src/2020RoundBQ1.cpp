//============================================================================
// Name        : 2020RoundBQ1.cpp
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
	int n, first = 0, second = 0, third = 0, peak = 0;
	cin >> n;

	cin >> first;
	cin >> second;

	for (int i = 2; i < n; i++) {
		cin >> third;

		if (second > first && second > third)
			peak++;
		first = second;
		second = third;
	}

	cout << peak << "\n";

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
