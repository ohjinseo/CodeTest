#include<iostream>
#include<algorithm>
#include<random>

constexpr auto MAX = 1001;
using namespace std;

int arr[MAX];


//my code
int test_1(int arr[], int n) {	
	int result = 0, dp[MAX];
	fill(dp, dp + n, 1);

	for (int i = 1; i < n; i++) {

		int max = 0;
		for (int k = 0; k < i; k++) {
			if (arr[k] < arr[i]) {
				max = max < dp[k] ? dp[k] : max;
			}
		}
		if (max != 0) {
			dp[i] += max;
			result = result < dp[i] ? dp[i] : result;
		}
	}
	return result;
}

int test_2(int arr[], int n) {
	int i, j, ans = 0;
	
	int dp[1001];

	for (i = 0; i < n; i++) {
		dp[i] = 0;
	}
	dp[0] = 1;
	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j]);
		}
		dp[i]++;
		ans = max(ans, dp[i]);
	}
	return ans;
}


int main() {
	
	while (true) {
		int n = rand() % 100;
		int arr[1001];

		for (int i = 0; i < n; i++) {
			int randomN = rand() % 1000;
			arr[i] = randomN;
		}

		int t1 = test_1(arr, n);
		int t2 = test_2(arr, n);

		if (t1!= t2) {
			cout << "Wrong Answer" << endl;
			cout << "Input : ";
			for (int i = 0; i < n; i++) {
				cout << arr[i] << " ";
			}

			cout << "\nMy Test : " << t1 << endl;
			cout << "Expect : " << t2 << endl;

			break;
		}
	}
}

