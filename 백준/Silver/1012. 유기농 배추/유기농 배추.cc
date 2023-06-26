#include <iostream>
using namespace std;

int m, n, k;

void dfs(int x, int y, bool* check[], int* arr[]) {
	check[x][y] = true;

	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (nextX > -1 && nextX<m && nextY>-1 && nextY < n) {
			if (arr[nextX][nextY] == 1 && check[nextX][nextY] == false) {
				dfs(nextX, nextY, check, arr);
			}
		}
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		cin >> m >> n >> k;

		int** arr = new int* [m];
		for (int i = 0; i < m; i++) {
			arr[i] = new int[n];
		}

		for (int a = 0; a < m; a++) {
			for (int b = 0; b < n; b++) {
				arr[a][b] = 0;
			}
		}


		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			arr[a][b] = 1;
		}

		bool** check = new bool* [m];
		for (int i = 0; i < m; i++) {
			check[i] = new bool[n] {false};
		}

		int result = 0;

		for (int a = 0; a < m; a++) {
			for (int b = 0; b < n; b++) {
				if (arr[a][b] == 1 && check[a][b] == false) {
					dfs(a, b, check, arr);
					result++;
				}
			}
		}

		cout << result << "\n";
		result = 0;
	}
}