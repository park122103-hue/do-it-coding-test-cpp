#include <iostream>
#include <vector>

using namespace std;

//연결 요소의 갯수를 구하는 프로그램
//노드의 번호는 1, 2, ..., N 으로 주어진다
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;	//노드 수, 에지 수
	cin >> N >> M;
	vector<bool> checked(N);	//확인된
	vector<int> s;	//스택
	vector<vector<int>> edge(N);	//노드 i-1에 연결된 에지

	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		edge[a-1].push_back(b);	//에지의 인덱스는 노드-1이다
		edge[b-1].push_back(a);	//b to a 에지는 edge(b-1)=a로 표현됨
	}
	
	int count = 1;
	s.push_back(1);
	checked[0] = true;
	while (!s.empty()) {
		int now = s.back();
		s.pop_back();
		while (!edge[now-1].empty()) {
			if (!checked[edge[now - 1].back()-1]) {
				s.push_back(edge[now-1].back());
				checked[edge[now-1].back()-1] = true;
			}
			edge[now-1].pop_back();
		}
		if (!s.empty()) continue;
		/*--여기까진 DFS--*/
		for (int i = 1; i <= N; i++) {
			if (!checked[i-1]) {	//DFS가 끝났을 때 아직 체크되지 않은 노드가 있다면
				count++;	//연결 요소가 하나 더 있다는 뜻이므로 count++
				s.push_back(i);	//DFS를 다시 시작하도록 스택에 해당 노드를 넣어준다
				checked[i-1] = true;	//해당 노드를 체크하고
				break;	//DFS를 재개한다
			}
		}
	}
	cout << count;
}
