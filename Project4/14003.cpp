#include<iostream>
#include<vector>
#include<stack>
#define INF 1000000001
using namespace std;

vector<int> list;
vector<pair<int, int>> ans;
stack<int> s;
int A[1000001];

int main() {
	int n;

	cin >> n;

	list.push_back(-1 * INF);
	for (int i = 0; i < n; i++) {
		cin >> A[i];


		if (A[i] > list.back()) {
			list.push_back(A[i]);
			//첫 번째 인자는 list에 들어갈 인덱스, 두 번째 인자는 현재 요소
			ans.push_back(make_pair(list.size() - 1, A[i]));
		}
		else {
			int lo = 0;
			int hi = list.size();

			while (lo < hi) {
				int mid = (lo + hi) / 2;
				if (A[i] == list.at(mid)) {
					lo = mid;
					break;
				}
				if (A[i] < list.at(mid)) {
					hi = mid;
				}
				else {
					lo = mid + 1;
				}
			}

			list.at(lo) = A[i];
			ans.push_back(make_pair(lo, A[i]));
		}
	}


	/*for (int i = 0; i < ans.size(); i++) {
		cout << ans.at(i).first << " " << ans.at(i).second << endl;
	}*/
	
	int t = list.size() - 1;
	cout << t << endl;
	
	for (int i = ans.size() - 1; i >= 0; i--) {
		if (ans.at(i).first == t) {
			s.push(ans.at(i).second);
			t--;
		}
	}
	int ss = s.size();
	for (int i = 0; i < ss; i++) {
		cout << s.top() << " ";
		s.pop();
	}
	

}