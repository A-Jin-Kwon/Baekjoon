#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	int dp[41];
	dp[0] = 0;
	dp[1] = 1;

	while (T--) {
		int N;
		cin >> N;

		for (int i = 2; i <= N; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}

		if (N == 0) {
			cout << "1 0\n";
			continue;
		}
		if (N == 1) {
			cout << "0 1\n";
			continue;
		}

		cout << dp[N - 1] << " " << dp[N] << "\n";
	}
}