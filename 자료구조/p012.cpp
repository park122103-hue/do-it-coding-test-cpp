#include <iostream>
#include <vector>
#include <stack>

using namespace std;
//구조체 썻지만 pair를 써도 좋다
typedef struct{
  int index, data;
}NODE;
//수열 A(i)에서 A(i)의 오큰수를 구하는 프로그램
//오큰수: A(i)보다 큰 오른쪽에 있는 수중 가장 왼쪽에 있는 수이고, A(i)보다 큰 오른쪽에 있는 수가 없다면 오큰수는 -1이다
int main() {
    int n;  //수열 길이
    cin >> n;
    stack<NODE> s;  //오큰수 대기열
    vector<int> NGE(n);  //NGE(i)=A(i)의 오큰수
  //규칙 1. 수열 A를 순서대로 스택에 넣는다
  //규칙 2. A(top)<A(i)이면 A(top)를 스택에서 제거한다
  //q1. A(0)보다 큰 수가 들어오면 A(0)은 제거될까(오큰수의 조건)?
  //a. A(0)보다 큰 수가 최초로 들어왔다면
  //b. A(0)보다 큰 수가 A(0) 바로 위로 들어오면 규칙 2에 의해 A(0)은 제거된다
  //c. A(0)보다 큰 수가 들어왔을 때 A(0)위에 A(i), ... , A(j)이 있었다면
  //d. A(0)보다 큰 수가 최초로 들어왔으므로 이전에 들어온 A(i), ... , A(j)는 A(0)보다 작다
  //e. 따라서 큰 수는 스택 안의 모든 수보다 크므로 스택 안의 모든 수는 순차적으로 제거된다
  //a1. 따라서 q1의 대답은 '그렇다' 이다.
    for (int i = 0; i < n; i++) {
        int now;
        cin >> now;  //now=A(i)
        while (!s.empty() && s.top().data < now) {
            NGE[s.top().index] = now;
            s.pop();
        }
        s.push({ i, now });
    }
  //오른쪽에 더 큰 수가 없다면 스택에서 제거되지 않고 남아있다
  //그 수들의 오큰수는 -1이다(오큰수의 정의)
    while (!s.empty()) {
        NGE[s.top().index] = -1;
        s.pop();
    }
  
    for (int i = 0; i < n; i++) {
        cout << NGE[i] << ' ';
    }
}
