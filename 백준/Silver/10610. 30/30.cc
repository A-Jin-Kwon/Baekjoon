#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	// 30의 배수 조건
	// 1: 끝 자리는 0
	// 2: 각 자리 수의 합이 3의 배수
	string str;
	cin >> str;
	
	bool isZero = false;

	for (long long i = 0; i < str.length(); i++) {
		if (str[i]-'0' == 0) {
			isZero = true;
			break;
		}
	}
	if (!isZero) {
		cout << -1;
		return 0;
	}

	long long sum = 0;
	for (long long i = 0; i < str.length(); i++) {
		sum += str[i] - '0';
	}
	if (sum % 3 != 0) {
		cout << -1;
		return 0;
	}

	long long* arr = new long long[str.length()];
	for (long long i = 0; i < str.length(); i++) {
		arr[i] = str[i] - '0';
	}

	sort(arr, arr + str.length());

	for (int i = str.length() - 1; i >= 0; i--) {
		cout << arr[i];
	}
}