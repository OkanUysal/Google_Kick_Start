//============================================================================
// Name        : 2020RoundAQ4.cpp
// Author      : Okan UYSAL
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;

int score = 0;

struct Node {
	map<char, Node*> a;
	int count;
	Node() {
		count = 0;
	}
};

void insert(Node *x, string s) {
	for (unsigned int i = 0; i < s.size(); i++) {
		if (x->a.count(s[i]) == 0) {
			x->a[s[i]] = new Node;
		}
		x = x->a[s[i]];
	}
	x->count++;
}

int recursive(Node *node, int count, int k) {
	int mode = node->count;
	map<char, Node*>::iterator it = node->a.begin();

	while (it != node->a.end()) {
		mode += recursive(it->second, count + 1, k);
		it++;
	}

	score += count * (mode / k);

	return mode % k;
}

void solve() {
	int n, k;
	string word;
	score = 0;
	struct Node *node = new Node;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> word;
		insert(node, word);

	}

	recursive(node, 0, k);

	cout << score << "\n";

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
