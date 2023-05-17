#include <iostream>
#include <math.h>
using namespace std;

int main() {
	long long n;
	cin >> n;

	long long result = pow(1 + (pow(2, n)), 2);
	cout << result;
}