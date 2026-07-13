#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(pair<int, int> s, pair<int, int> e, vector<vector<bool>> &map, vector<vector<bool>> &visited, int &count);

//void print_visit(vector<vector<bool>>& visited, int depth) {
//	int N = visited.size();
//	int M = visited[0].size();
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cout << visited[i][j];
//		}
//		cout << '\n';
//	}
//	cout << depth << '\n' << '\n';
//}

//미로 탐색하기(백준 2178)
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//N<=1000 M<=10000
	int N, M;
	cin >> N >> M;

	vector<vector<bool>> maze(N, vector<bool>(M));
	vector<vector<bool>> visited(N, vector<bool>(M));

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			maze[i][j] = str[j] - '0';
		}
	}

	int count = 0;
	pair<int, int> start = { 0, 0 };
	pair<int, int> end = { N - 1, M - 1 };
	bfs(start, end, maze, visited, count);

	cout << count;
	return 0;
}

void bfs(pair<int, int> s, pair<int, int> e, vector<vector<bool>>& map, vector<vector<bool>>& visited, int &count) {
	//필요한 자료형을 선언
	queue<pair<int, int>> q;	//que
	queue<int> depth;
	vector<int> dx = { 1, 0, -1, 0 };
	vector<int> dy = { 0, 1, 0, -1 };
	int N = map.size();
	int M = map[0].size();
	//시작 노드 s를 기록
	visited[s.first][s.second] = true;
	q.push(s);
	depth.push(1);
	//시작 노드를 방문하고 인접 노드를 기록
	//que가 빌 때까지 진행
	while (!q.empty()) {
		//현재 노드를 방문
		pair<int, int> now = q.front();
		count = depth.front();
		q.pop();
		depth.pop();
		//print_visit(visited, count);
		//현재 노드 now의 인접하며 방문하지 않은 노드를 기록
		for (int k = 0; k < 4; k++) {	//인접 조건을 만족하면
			pair<int, int> w;
			w.first = now.first + dx[k];
			w.second = now.second + dy[k];
			if (w == e) {
				count++;
				return;
			}
			if (w.first < N && w.first >= 0 && w.second < M && w.second >= 0 && map[w.first][w.second] && !visited[w.first][w.second]) {
				visited[w.first][w.second] = true;
				q.push(w);
				depth.push(count + 1);
			}
		}
	}
}

