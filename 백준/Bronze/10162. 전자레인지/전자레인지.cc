#include <iostream>
using namespace std;

int main() {
	int a = 300;
	int b = 60;
	int c = 10;
	
	int ac = 0;
	int bc = 0;
	int cc = 0;
	int impossible = false;

	int t;
	cin >> t;

	while (t != 0) {
		if (t >= 300) {
			t -= 300;
			ac++;
		}
		else if (t >= 60) {
			t -= 60;
			bc++;
		}
		else if (t >= 10) {
			t -= 10;
			cc++;
		}
		else {
			impossible = true;
			break;
		}
	}

	if (impossible) cout << -1;
	else cout << ac << " " << bc << " " << cc;
}