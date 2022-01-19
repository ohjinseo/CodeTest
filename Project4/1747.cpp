#include<iostream>
#include<string>
#define maxN 2000001
using namespace std;

int N;
bool arr[maxN];

void Eratos() {
	arr[1] = false;

	for (int i = 2; i < maxN; i++) {
		arr[i] = true;
	}

	//왜 i = N을 할시 버퍼오버런이 발생할까???
	for (int i = 2; i * i < maxN; i++) {
		if (arr[i]) {
			for (int j = i * i; j < maxN; j += i) {
				arr[j] = false;
			}
		}
	}
}

bool isPalindrome(int n) {
	if (n < 10) {
		return true;
	}
	else {
		string s = to_string(n);
		int l = s.length();
		for (int i = 0; i < l / 2; i++) {
			if (s[i] != s[l - i - 1]) return false;
		}
		return true;
	}
}

int main() {
	cin >> N;

	Eratos();

	for (int i = N; i < maxN; i++) {
		if (arr[i]) {

			if (isPalindrome(i)) {
				cout << i;
				break;
			}
		}
	}


}