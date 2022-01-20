#include<iostream>
#include<queue>
#define maxN 100001
using namespace std;

int N, K, minTime = -1, cnt;
bool visit[maxN];

//1 3일 때 2(1+1) + 1과 2(1*2) + 1이 있으므로 2 2가 출력되야됨 
//bfs 최적화만하다가 샷건치는 문제

bool check(int val) {
	if (val >= 0 && val < maxN && !visit[val]) return true;
	return false;
}

void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(N, 0));
	visit[N] = true;

	bool flag = false;	//최초 minTime을 업뎃했는지 

	while (!q.empty()) {
		int val = q.front().first;
		int depth = q.front().second;

		
		visit[val] = true;

		q.pop();

		//flag가 true이면서 depth가 minTime가 일치하지 않는다면 break
		if (flag && depth != minTime) {
			break;
		}

		if (val == K && !flag) {	//최초 minTime 발견 시 minTime 업뎃
			minTime = depth;
			flag = true;
			cnt++;
		}
		// 그 다음부터 minTime과 같은 val 발견 시 cnt++
		else if (val == K && flag && depth == minTime) {
			cnt++;
		}

		//이미 minTime을 찾은 순간 더이상 push할 필요 없음
		if (minTime == depth) {
			continue;
		}

		if (check(val - 1)) {
			q.push(make_pair(val - 1, depth + 1));
		}

		if (check(val + 1)) {
			q.push(make_pair(val + 1, depth + 1));


		}

		if (check(val * 2)) {
			q.push(make_pair(val * 2, depth + 1));

		}

	}
}

int main() {

	cin >> N >> K;
	
	bfs();

	cout << minTime << "\n" << cnt;
	
}