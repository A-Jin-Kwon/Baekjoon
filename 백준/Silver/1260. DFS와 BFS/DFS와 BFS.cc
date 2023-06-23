#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void dfs(int x, bool check[], vector<int> vec[]) {
	check[x] = true;
	cout << x << " ";

	for (int i = 0; i < vec[x].size(); i++) {
		if (!check[vec[x][i]]) {
			dfs(vec[x][i], check, vec);
		}
	}
}

void bfs(int start, bool check[], vector<int> vec[]) {
	queue<int> q;
	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " ";

		for (int i = 0; i < vec[x].size(); i++) {
			if (!check[vec[x][i]]) {
				q.push(vec[x][i]);
				check[vec[x][i]] = true;
			}
		}
	}
}

int main() {
	int n, m, v;
	cin >> n >> m >> v;

	bool* check = new bool[n + 1];
	vector<int>* vec = new vector<int>[n + 1];

	for (int i = 0; i < n + 1; i++) {
		check[i] = false;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 1; i < n + 1; i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	dfs(v, check, vec);
	for (int i = 0; i < n + 1; i++) {
		check[i] = false;
	}
	cout << "\n";
	bfs(v, check, vec);

	return 0;
}