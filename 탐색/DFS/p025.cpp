#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> edge;
static vector<bool> visited;
static bool arrive;

void dfs(int v, int depth);

//친구 관계 파악하기 (백준 13023)
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	edge.resize(N);
	visited = vector<bool>(N, false);
	arrive = false;
	for (int i = 0; i < M; i++) {
		int v, w;
		cin >> v >> w;
		edge[v].push_back(w);
		edge[w].push_back(v);
	}

	for (int i = 0; i < N; i++) {
		if (!arrive) {
			dfs(i, 1);
		}
	}
	cout << arrive;
	return 0;
}

void dfs(int v, int depth) {
	//문제 조건 만족 확인
	if (depth == 5 || arrive) {
		arrive = true;
		return;
	}
	//현재 노드 방문
	visited[v] = true;
	//인접 노드, 깊이+1 탐색
	while (!edge[v].empty()) {
		int w = edge[v].back();
		edge[v].pop_back();
		dfs(w, depth + 1);
	}
	//인접 노드를 탐색후 돌아올 때 
	visited[v] = false;
}
