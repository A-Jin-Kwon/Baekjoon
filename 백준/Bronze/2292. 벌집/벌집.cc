#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int idx = 1;

	int start = 0;
	int end = 1;

	while (!(start <= n && n <= end)) {
		idx++;
		start = end + 1;
		end = end + (6 * (idx - 1));
	}

	cout << idx;
}