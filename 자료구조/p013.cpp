#include <iostream>
#include <deque>

using namespace std;
//카드덱의 맨 윗장을 버리고, 다음 장을 맨 아래로 넣는 것을 반복했을 때 마지막에 남는 카드를 구하는 프로그램
int main() {
    int n;
    cin >> n;
    deque<int> dq;

    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    for (int i = 1; i < n; i++) {
        dq.pop_front();
        int tmp = dq.front();
        dq.pop_front();
        dq.push_back(tmp);
    }

    cout << dq.front();
}
