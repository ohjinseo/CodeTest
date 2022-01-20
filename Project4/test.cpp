#include<iostream>
using namespace std;

long long dp[65][11];

long long calculate(int n) {
	if (n == 1) {
		return 10;
	}
	else {
		//2자리수 초기화
		for (int i = 0; i < 10; i++) {
			dp[2][i] = 10 - i;
			dp[2][10] += dp[2][i];
		}

		for (int i = 3; i <= n; i++) {
			for (int j = 0; j < 10; j++) {
				if (j == 0) {
					dp[i][j] = dp[i - 1][10];
					dp[i][10] += dp[i - 1][10];
				}
				else {
					dp[i][j] = dp[i][j - 1] - dp[i - 1][j - 1];
					dp[i][10] += dp[i][j];
				}
			}
		}

		return dp[n][10];
	}
}

void showArray(int n) {
	for (int i = 0; i <= n; i++) {
		cout << "----" << i << "번째입니다. -----" << endl;
		for (int j = 0; j < 11; j++) {
			cout << dp[i][j] << endl;
		}
	}
}

void initArray() {
	for (int i = 0; i < 65; i++) {
		for (int j = 0; j < 11; j++) {

			dp[i][j] = 0;
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;

		cout << calculate(n) << endl;
		//showArray(n);

		initArray();

	}
}

