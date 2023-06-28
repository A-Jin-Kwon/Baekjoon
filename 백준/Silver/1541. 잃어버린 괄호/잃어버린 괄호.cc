#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	bool isMinus = false;
	string tmp = "";
	int result = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '+' || str[i] == '-') {
			if (isMinus) {
				result -= stoi(tmp);
				tmp = "";
			}
			else {
				result += stoi(tmp);
				tmp = "";
			}
		}
		else {
			tmp += str[i];
		}

		if (str[i] == '-') {
			isMinus = true;
		}
	}
	if (isMinus) result -= stoi(tmp);
	else result += stoi(tmp);

	cout << result;
	return 0;
}