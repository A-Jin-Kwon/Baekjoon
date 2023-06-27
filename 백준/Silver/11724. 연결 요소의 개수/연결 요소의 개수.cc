#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int x, vector<int> vec[], bool check[]) {
	check[x] = true;

	for (int i = 0; i < vec[x].size(); i++) {
		if (!check[vec[x][i]]) {
			dfs(vec[x][i], vec, check);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<int>* vec = new vector<int>[n + 1];

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	bool* check = new bool[n+1] {false};
	int result = 0;

	for (int i = 1; i <= n; i++) {
		if (check[i] == true) continue;
		else {
			dfs(i, vec, check);
			result++;
		}
	}

	cout << result;
}