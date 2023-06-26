#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;

void bfs(int x, int y, int* check[], int* arr[]) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = 1;


	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		int dx[4] = { 1, -1, 0, 0 };
		int dy[4] = { 0, 0, 1, -1 };

		for (int i = 0; i < 4; i++) {
			int next_x = row + dx[i];
			int next_y = col + dy[i];

			if (next_x > -1 && next_x<n && next_y>-1 && next_y < m) {
				if (arr[next_x][next_y] == 1 && check[next_x][next_y] == 0) {
					q.push(make_pair(next_x, next_y));
					check[next_x][next_y] = check[row][col] + 1;
				}
			}
		}
	}

	cout << check[n - 1][m - 1];
};

int main() {
	cin >> n >> m;

	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	int** check = new int* [n];
	for (int i = 0; i < n; i++) {
		check[i] = new int[m];
	}

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		for (int z = 0; z < str.length(); z++) {
			arr[i][z] = str[z] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int z = 0; z < m; z++) {
			check[i][z] = 0;
		}
	}

	bfs(0, 0, check, arr);
	return 0;
}