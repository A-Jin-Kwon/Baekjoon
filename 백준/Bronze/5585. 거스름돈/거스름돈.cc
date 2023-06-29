#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	n = 1000 - n;

	int coin = 0;

	while (n != 0) {
		if (n >= 500) {
			n -= 500;
			coin++;
		}
		else if (n >= 100) {
			n -= 100;
			coin++;
		}
		else if (n >= 50) {
			n -= 50;
			coin++;
		}
		else if (n >= 10) {
			n -= 10;
			coin++;
		}
		else if (n >= 5) {
			n -= 5;
			coin++;
		}
		else if (n >= 1) {
			n -= 1;
			coin++;
		}
	}

	cout << coin;
}