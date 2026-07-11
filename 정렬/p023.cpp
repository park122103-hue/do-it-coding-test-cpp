#include <iostream>
#include <vector>

using namespace std;

//N개의 자연수가 주어졌을 때 계수 정렬하는 프로그램
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<bool> checked(N);
	vector<int> s;
	vector<vector<int>> edge(N);

	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		edge[a-1].push_back(b);
		edge[b-1].push_back(a);
	}

	int count = 1;
	s.push_back(1);
	checked[0] = true;
	while (!s.empty()) {
		int now = s.back();
		s.pop_back();
		while (!edge[now-1].empty()) {
			if (checked[edge[now - 1].back()-1]) {
				s.push_back(edge[now-1].back());
				checked[edge[now-1].back()-1] = true;
			}
			edge[now-1].pop_back();
		}
		if (!s.empty()) continue;
		for (int i = 1; i <= N; i++) {
			if (!checked[i-1]) {
				count++;
				s.push_back(i);
				checked[i-1] = true;
				break;
			}
		}
	}
	cout << count;
}
