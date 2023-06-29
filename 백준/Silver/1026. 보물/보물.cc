#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int* a = new int[n];
	int* b = new int[n];

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a[i] = tmp;
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		b[i] = tmp;
	}

	sort(a, a + n);
	sort(b, b + n);

	int result = 0;

	for (int i = 0; i < n; i++) {
		result += a[i] * b[n - i - 1];
	}

	cout << result;
	return 0;
}