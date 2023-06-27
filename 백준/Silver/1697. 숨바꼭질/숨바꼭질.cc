#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	queue<pair<int, int>> q;

	q.push(make_pair(n, 0));
	bool check[200002]{ false };

	int result = 0;

	while (!q.empty()) {
		int val = q.front().first;
		int level = q.front().second;
		q.pop();
		check[val] = true;

		if (val == k) {
			result = level;
			break;
		}

		int left = val - 1;
		int right = val + 1;
		int tele = val * 2;

		if (left >= 0 && left <= 100000 && check[left] == false) {
			q.push(make_pair(left, level + 1));
		}
		if (right >= 0 && right <= 100000 && check[right] == false) {
			q.push(make_pair(right, level + 1));
		}
		if (tele >= 0 && tele <= 100000 && check[tele] == false) {
			q.push(make_pair(tele, level + 1));
		}
	}

	cout << result;

	return 0;
}