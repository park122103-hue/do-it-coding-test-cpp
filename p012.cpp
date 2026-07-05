#include <iostream>
#include <vector>
#include <stack>

using namespace std;
//구조체 썻지만 pair를 써도 좋다
typedef struct{
  int index, data;
}NODE;
//수열 A(i)에서 A(i)보다 큰 오른쪽에 있는 수중 가장 왼쪽에 있는 수(오큰수)를 구하는 프로그램
int main() {
    int n;
    cin >> n;
    stack<NODE> s;
    vector<int> NGE(n);

    for (int i = 0; i < n; i++) {
        int now;
        cin >> now;
        while (!s.empty() && s.top().data < now) {
            NGE[s.top().index] = now;
            s.pop();
        }
        s.push({ i, now });
    }

    for (int i = 0; i < s.size(); i++) {
        NGE[s.top().index] = -1;
        s.pop();
    }

    for (int i = 0; i < n; i++) {
        cout << NGE[i] << ' ';
    }
}
