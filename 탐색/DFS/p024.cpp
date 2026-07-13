#include <iostream>
#include <vector>

using namespace std;

//소수면 1, 소수가 아니면 0
bool is_decimal(int x);

//신기한 소수 찾기 (백준 2023)
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	vector<int> s;
	for (int x : {2, 3, 5, 7}) {
		//dfs(x);
		s.push_back(x);
		while (!s.empty()) {
			int now = s.back();
			if (now > pow(10, N - 1)) {
				cout << now << '\n';
			}
			s.pop_back();
			for (int y : {9, 7, 5, 3, 1}) {
				if (10 * now + y < pow(10, N) && is_decimal(10 * now + y)) {
					s.push_back(10 * now + y);
				}
			}
		}
		while (!s.empty()) {
			s.pop_back();
		}
	}
}



bool is_decimal(int x) {
  if (x == 1) return 0;
	for (int p = 2; p <= sqrt(x); p++) {
		if (x % p == 0) {
			return 0;
		}
	}
	return 1;
}
