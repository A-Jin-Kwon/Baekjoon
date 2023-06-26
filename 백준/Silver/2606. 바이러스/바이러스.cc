#include <iostream>
#include <vector>
using namespace std;

int result = 0;

void dfs(int x, bool check[], vector<int> vec[]) {
	check[x] = true;
	result++;

	for (int i = 0; i < vec[x].size(); i++) {
		if (check[vec[x][i]] == false) {
			dfs(vec[x][i], check, vec);
		}
	}
}

int main() {
	int n, m; //컴퓨터, 간선의 수
	cin >> n >> m;

	vector<int>* vec = new vector<int>[n + 1];
	bool* check = new bool[n + 1];
	fill(check, check + n + 1, false);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	dfs(1, check, vec);
	cout << result - 1;
	return 0;
}