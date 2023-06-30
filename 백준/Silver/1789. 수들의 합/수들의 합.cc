#include <iostream>
using namespace std;

int main() {
	long long s;
	cin >> s;

	long long start = 1; //시작
	long long number = 2; //개수
	long long result = 1; //항수

	while (!(s < start + number)) {
		start = start + number;
		number++;
		result++;
	}

	cout << result;
}