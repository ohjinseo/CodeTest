#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define maxN 1000001
#include<vector>
using namespace std;

int A[maxN];
vector<int> lis;

int main() {
	int N;
	lis.push_back(0);

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);


		if (A[i] > lis.back()) { 
			lis.push_back(A[i]);
		}
		
		else {	
			int lo = 0;

			int hi = lis.size();

			while (lo < hi) {
				int mid = (lo + hi) / 2;

				if (lis.at(mid) == A[i]) {
					lo = mid; break;
				}
				else if (A[i] <= lis.at(mid)) {
					hi = mid;
				}
				else {
					lo = mid + 1;
				}
			}
			lis.at(lo) = A[i];
		}
	}
	printf("%d", lis.size() - 1);
}