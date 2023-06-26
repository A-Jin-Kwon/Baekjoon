#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int cnt = 0;

int dfs(int a, int b, bool* check[], int* arr[]) {
	check[a][b] = true;

	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	for (int i = 0; i < 4; i++) {
		int nextX = a + dx[i];
		int nextY = b + dy[i];

		if (nextX > -1 && nextX<n && nextY>-1 && nextY < n) {
			if (arr[nextX][nextY] == 1 && check[nextX][nextY] == false) {
				cnt++;
				dfs(nextX, nextY, check, arr);
			}
		}
	}

	return cnt + 1;
}

int main() {
	cin >> n;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		for (int a = 0; a < str.length(); a++) {
			arr[i][a] = str[a] - '0';
		}
	}

	bool** check = new bool* [n];
	for (int i = 0; i < n; i++) {
		check[i] = new bool[n] {false};
	}

	vector<int> result;

	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			if (arr[a][b] == 1 && check[a][b] == false) {
				int houses = dfs(a, b, check, arr);
				result.push_back(houses);
				cnt = 0;
			}
		}
	}

	cout << result.size() << "\n";
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	return 0;
}