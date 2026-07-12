#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

static vector<vector<int>> edge;
static vector<bool> visited;
static deque<int> dfs_order;
static deque<int> bfs_order;

void dfs(int v);
void bfs(int v);

//DFS와 BFS 프로그램(백순 1260)
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//N<=1000 M<=10000
	int N, M, S;
	cin >> N >> M >> S;

	edge.resize(N);
	for (int i = 0; i < M; i++) {
		int v, w;
		cin >> v >> w;
		edge[v - 1].push_back(w - 1);
		edge[w - 1].push_back(v - 1);
	}

	for (int i = 0; i < N; i++) {
		sort(edge[i].begin(), edge[i].end());
	}

	visited = vector<bool>(N, false);
	dfs(S - 1);
	visited = vector<bool>(N, false);
	bfs(S - 1);

	while (!dfs_order.empty()) {
		cout << dfs_order.front() + 1 << ' ';
		dfs_order.pop_front();
	}
	cout << '\n';
	while (!bfs_order.empty()) {
		cout << bfs_order.front() + 1 << ' ';
		bfs_order.pop_front();
	}
	cout << '\n';
	return 0;
}

void dfs(int v) {
	//현재 노드가 방문되지 않은 노드라면
	if (visited[v]) return;
	//현재 노드 탐색
	visited[v] = true;
	dfs_order.push_back(v);
	//인접 노드 탐색 시작
	for (int i = 0; i < edge[v].size(); i++) {
		int w = edge[v][i];
		dfs(w);
	}
}

void bfs(int v) {
	//필요한 자료형을 선언
	deque<int> q;	//que
	//시작 노드 v를 기록
	visited[v] = true;
	q.push_back(v);
	//시작 노드를 방문하고 인접 노드를 기록
	//que가 빌 때까지 진행
	while (!q.empty()) {
		//현재 노드를 방문
		int now = q.front();
		q.pop_front();
		//탐색 순서를 기록
		bfs_order.push_back(now);
		//현재 노드 now의 인접하며 방문하지 않은 노드를 기록
		for (int i = 0; i < edge[now].size(); i++) {	//조건: 인접 리스트 edge[now]의 리스트를 모두 기록
			if (!visited[edge[now][i]]) {
				visited[edge[now][i]] = true;
				q.push_back(edge[now][i]);
			}
		}
	}
}
