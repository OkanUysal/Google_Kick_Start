//============================================================================
// Name        : 2020RoundBQ3.cpp
// Author      : Okan UYSAL
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define BOUNDARY 1000000000

void solve() {
	string direction;
	long long row = 1, coloum = 1;
	int value = 0;
	cin >> direction;
	vector<long long> stack;
	stack.push_back(1);

	int lenght = direction.length();

	for (int i = 0; i < lenght; i++) {
		if (direction[i] == 'N') {
			coloum -= stack[value];
			if (coloum < 1) {
				coloum += BOUNDARY;
			}
		} else if (direction[i] == 'S') {
			coloum += stack[value];
			if (coloum > BOUNDARY) {
				coloum -= BOUNDARY;
			}
		} else if (direction[i] == 'W') {
			row -= stack[value];
			if (row < 1) {
				row += BOUNDARY;
			}
		} else if (direction[i] == 'E') {
			row += stack[value];
			if (row > BOUNDARY) {
				row -= BOUNDARY;
			}
		} else if (direction[i] >= '2' && direction[i] <= '9') {
			stack.push_back((stack[value] * (direction[i] - 48)) % BOUNDARY);
			value++;
		} else if (direction[i] == ')') {
			value--;
			stack.pop_back();
		}
	}

	cout << row << " " << coloum << "\n";

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
