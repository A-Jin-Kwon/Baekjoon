#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int* roadLength = new int[n - 1];
	int* price = new int[n];

	for (int i = 0; i < n - 1; i++) {
		cin >> roadLength[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}

	int minPrice = 1000000001;
	int minIndex = -1;
	// 마지막 도시 가격을 제외한 가격 중 최소
	for (int i = 0; i < n - 1; i++) {
		if (price[i] < minPrice) {
			minPrice = price[i];
			minIndex = i;
		}
	}
	
	int result = 0;
	for (int i = 0; i < minIndex; i++) {
		result += price[i] * roadLength[i];
	}
	int roadSum = 0;
	for (int i = minIndex; i < n - 1; i++) {
		roadSum += roadLength[i];
	}
	result += roadSum * minPrice;

	cout << result;
}