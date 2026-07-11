#include <iostream>
#include <vector>

using namespace std;

//N개의 자연수가 주어졌을 때 계수 정렬하는 프로그램
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> count(10001);
	for (int i = 0; i < N; i++) {
		int now;
		cin >> now;
		count[now]++;
	}
	int n = 0;
	for (int i = 0; i < 10001; i++) {
		while (count[i] > 0) {
			cout << i << '\n';
			count[i]--;
		}
	}
	return 0;
}
