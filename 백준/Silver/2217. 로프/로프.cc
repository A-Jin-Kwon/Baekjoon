#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long n;
	cin >> n;

	long long* arr = new long long[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//오름차순 정렬
	sort(arr, arr + n);
	int result = -1;
	int idx = 1;

	for (int i = n - 1; i >= 0; i--) {
		int tmp = idx * arr[i];
		if (result < tmp) {
			result = tmp;
		}
		idx++;
	}

	cout << result;
}