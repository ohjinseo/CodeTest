#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

string files[51];
vector<string> v;

bool compare(string wildPattern, string file) {
	//wildPattern : *********a
	//file : aaaaaaab 
	// 
	//cout << "------------- " << wildPattern << "   " << file << endl;

	int pos = 0;
	//pos�� �ι��ڿ��� ���̸� ���� �����鼭 ���ϰ� ���� ���ڰ� ���ų� ���� ���ڰ� '?'�� ��� pos + 1�Ѵ�
	//���� ���ڰ� '*'�� �����ų�, pos�� �ʰ��ǰų�, ������ '?'�� �ƴϸ鼭 �� ���ڰ� �ٸ��ٸ� while���� �������´�
	while (pos < file.size() && pos < wildPattern.size() && (wildPattern[pos] == file[pos] || wildPattern[pos] == '?')) {
		pos++;
	}

	//���� ���� ������ ��� -> file�� ���� �����ؾ� ������
	if (pos == wildPattern.size()) 
		return pos == file.size();
	
	//���� ���ڰ� '*'�� ���� ��� '*'�� �� ���ڰ� �����ؾ� ���� Ȯ��
	//W => s?p*e*n
	//F => sqpiderman
	//compare(e*n, {iderman, ... erman}) ��� ȣ�� => 
	//pos = 1, compare(n, {derman, erman, rman, man, an, n}) => compare(n, n) => true
	//compare(e*n, {iderman}) => true
	if (wildPattern[pos] == '*') {
		for (int skip = 0; pos + skip <= file.size(); skip++) {
			
			if (compare(wildPattern.substr(pos + 1), file.substr(pos + skip))) {
				return true;
			}
		}
	}
	//�ܴ̿� false
	return false;
}

int main() {
	int TC;
	cin >> TC;
	for (int t = 0; t < TC; t++) {
		string wildPattern;

		cin >> wildPattern;

		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> files[i];
			if (compare(wildPattern, files[i])) {
				v.push_back(files[i]);
			}
		}
	}
	sort(v.begin(), v.end());

	for (string s : v) {
		cout << s << endl;
	}

}