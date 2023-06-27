#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int result = 0;

	while (n != 0) {
		if (n < 3) {
			result = -1;
			break;
		}

		if (n % 5 == 0) {
			n -= 5;
			result++;
		}
		else {
			n -= 3;
			result++;
		}
	}

	cout << result;
	return 0;
}