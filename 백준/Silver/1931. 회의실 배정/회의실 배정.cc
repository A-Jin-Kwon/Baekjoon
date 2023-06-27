#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> vec;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		vec.push_back(make_pair(b, a));
	}

	// 끝나는 시간 기준 정렬
	sort(vec.begin(), vec.end());

	int end_time = vec[0].first;
	int result = 1;

	for (int i = 1; i < n; i++) {
		if (vec[i].second >= end_time) {
			result++;
			end_time = vec[i].first;
		}
	}

	cout << result;
}