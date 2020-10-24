//============================================================================
// Name        : 2020RoundAQ3.cpp
// Author      : Okan UYSAL
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void solve() {
	int n, k, minDiff = 1, maxDiff = 1, current = 0, temp = 0, average = 0;
	int lastAverage = 0;

	cin >> n >> k;

	vector<int> a(n - 1);

	cin >> current;

	for (int i = 0; i < n - 1; i++) {
		cin >> temp;
		a[i] = temp - current;
		maxDiff = max(maxDiff, a[i]);
		current = temp;
	}

	while(true) {
		if(maxDiff < minDiff) {
			break;
		}
		average = (minDiff + maxDiff) / 2;

		int req = 0;
		for(int i = 0; i < n - 1; i++) {
			if(average < a[i]) {
				if(a[i] % average == 0) {
					req += floor((a[i] - 1)/(double)average);
				} else {
					req += floor(a[i]/(double)average);
				}

			}
		}

		if(req <= k) {
			maxDiff = average - 1;
			lastAverage = average;
		} else if( req > k) {
			minDiff = average + 1;
		}


	}

	cout << lastAverage << "\n";
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
