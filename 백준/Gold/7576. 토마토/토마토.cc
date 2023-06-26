#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
int m, n;

void bfs(int* check[], int* arr[]) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int dx[4] = { 1, -1, 0, 0 };
		int dy[4] = { 0, 0, 1, -1 };

		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if (nextX > -1 && nextX<n && nextY>-1 && nextY < m) {
				if (arr[nextX][nextY] == 0 && check[nextX][nextY] == 0) {
					check[nextX][nextY] = check[x][y] + 1;
					q.push(make_pair(nextX, nextY));
				}
			}
		}
	}

	// 토마토가 모두 익지 못하는 상황
	for (int a = 0; a < n; a++) {
		for (int b = 0;b < m;b++) {
			if (check[a][b] == 0) {
				cout << -1;
				return;
			}
		}
	}

	int max = -1;
	for (int a = 0; a < n; a++) {
		for (int b = 0;b < m;b++) {
			if (max<check[a][b]) {
				max = check[a][b];
			}
		}
	}

	if (max == 1) cout << 0; // 저장될 때부터 모두 익어있는 상태
	else cout << max - 1; // 모두 익을 때까지의 최소 날짜
};

int main() {
	cin >> m >> n;

	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}

	int** check = new int* [n];
	for (int i = 0; i < n; i++) {
		check[i] = new int[m] {0};
	}

	for (int a = 0; a < n; a++) {
		for (int b = 0; b < m;b++) {
			cin >> arr[a][b];
			
			if (arr[a][b] == 1) {
				check[a][b] = 1;
				q.push(make_pair(a, b));
			}
			else if (arr[a][b] == -1) {
				check[a][b] = -1;
			}
			else {
				check[a][b] = 0;
			}
		}
	}

	bfs(check, arr);
}