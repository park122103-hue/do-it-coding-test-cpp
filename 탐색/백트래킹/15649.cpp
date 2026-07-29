#include <iostream>
#include <vector>

using namespace std;

vector<bool> checked;
vector<int> dfs_array;
void dfs(int n, int m, int v, int depth);

//1부터 N까지의 자연수 중에서 중복없이 M개를 고른 수열을 구하는 프로그램
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//1<=N<=M<=8
	int N, M;
	cin >> N >> M;

	checked = vector<bool> (N + 1);
	dfs_array.push_back(0);
	for (int v = 1; v <= N; v++) {
		checked[v] = true;
		dfs_array.push_back(v);
		dfs(N, M, v, 1);
		dfs_array.pop_back();
		checked[v] = false;
	}
}

void dfs(int n, int m, int v, int depth) {
	//깊이가 M이면 백트래킹을 종료한다. 그렇지 않다면,
	if (depth >= m) {
		for (int i = 1; i <= m; i++) {
			cout << dfs_array[i];
		}
		cout << '\n';
		return;
	}
	//백트래킹의 조건에 맞는 노드를 차례로 순회(dfs)한다.
	for (int w = 1; w <= n; w++) {
		if (!checked[w]) {
			checked[w] = true;
			dfs_array.push_back(w);
			dfs(n, m, w, depth + 1);
			dfs_array.pop_back();
			checked[w] = false;
		}
	}
	//백트래킹의 조건은, 이전에 지나오지 않았던 노드여야 한다.
	//현재 깊이의 노드들은 현재의 순회 조건으로 충족된다.
}

