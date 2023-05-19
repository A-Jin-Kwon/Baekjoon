#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	int coin[4]{ 25, 10, 5, 1 };

	while (T--) {
		int result[4]{ 0,0,0,0 };

		int c;
		cin >> c;
		
		int idx = 0;
		while (c > 0) {
			if (c >= coin[idx]) {
				result[idx]++;
				c -= coin[idx];
			}
			else {
				idx++;
			}
		}

		for (int i = 0; i < 4; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
	}
}