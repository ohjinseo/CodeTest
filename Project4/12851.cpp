#include<iostream>
#include<queue>
#define maxN 100001
using namespace std;

int N, K, minTime = -1, cnt;
bool visit[maxN];

//1 3�� �� 2(1+1) + 1�� 2(1*2) + 1�� �����Ƿ� 2 2�� ��µǾߵ� 
//bfs ����ȭ���ϴٰ� ����ġ�� ����

bool check(int val) {
	if (val >= 0 && val < maxN && !visit[val]) return true;
	return false;
}

void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(N, 0));
	visit[N] = true;

	bool flag = false;	//���� minTime�� �����ߴ��� 

	while (!q.empty()) {
		int val = q.front().first;
		int depth = q.front().second;

		
		visit[val] = true;

		q.pop();

		//flag�� true�̸鼭 depth�� minTime�� ��ġ���� �ʴ´ٸ� break
		if (flag && depth != minTime) {
			break;
		}

		if (val == K && !flag) {	//���� minTime �߰� �� minTime ����
			minTime = depth;
			flag = true;
			cnt++;
		}
		// �� �������� minTime�� ���� val �߰� �� cnt++
		else if (val == K && flag && depth == minTime) {
			cnt++;
		}

		//�̹� minTime�� ã�� ���� ���̻� push�� �ʿ� ����
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