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
	//pos가 두문자열의 길이를 넘지 않으면서 패턴과 파일 문자가 같거나 패턴 문자가 '?'일 경우 pos + 1한다
	//패턴 문자가 '*'를 만나거나, pos가 초과되거나, 패턴이 '?'이 아니면서 두 문자가 다르다면 while문을 빠져나온다
	while (pos < file.size() && pos < wildPattern.size() && (wildPattern[pos] == file[pos] || wildPattern[pos] == '?')) {
		pos++;
	}

	//패턴 끝에 도달한 경우 -> file명도 끝에 도달해야 대응됨
	if (pos == wildPattern.size()) 
		return pos == file.size();
	
	//패턴 문자가 '*'를 만날 경우 '*'에 몇 글자가 대응해야 할지 확인
	//W => s?p*e*n
	//F => sqpiderman
	//compare(e*n, {iderman, ... erman}) 재귀 호출 => 
	//pos = 1, compare(n, {derman, erman, rman, man, an, n}) => compare(n, n) => true
	//compare(e*n, {iderman}) => true
	if (wildPattern[pos] == '*') {
		for (int skip = 0; pos + skip <= file.size(); skip++) {
			
			if (compare(wildPattern.substr(pos + 1), file.substr(pos + skip))) {
				return true;
			}
		}
	}
	//이외는 false
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