#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int* arr = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	sort(arr + 1, arr + n + 1);

	int idx = 1;
	int sum = 0;

	while (idx <= n) {
		for (int i = 1; i <= idx; i++) {
			sum += arr[i];
		}
		idx++;
	}

	cout << sum;
	return 0;
}