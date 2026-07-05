#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
//N개의 수 A(1), ... , A(N)이 주어진다
//A(i-L+1), ... , A(i)중 가장 작은 값 D(i)를 구하는 프로그램
int main() {
    int num, len;    //N, L
    deque<pair<int,int>> dq;
    cin >> num >> len;
    for (int i = 0; i < num; i++) {
        int now;    //now=A(i)
        cin >> now;
        //A(i)가 가장 작은 값이라면 A(i-1), ... , A(1)은 버려도 된다
        //A(i)보다 작은 값이 있다면 그 값이 범위를 벗어나 제거되고 자신의 차례가 올 때까지 A(i)는 그 값 뒤에 대기 한다
        while (!dq.empty() && now <= dq.back().first) {
            dq.pop_back();
        }
        dq.push_back({ now, i });
        //큐 맨 앞의 인덱스가 i-L+1의 범위를 벗어나면 제거된다
        while (!dq.empty() && i - len >= dq.front().second) {
            dq.pop_front();
        }
        //큐 맨 앞의 값이 A(i-L+1), ... , A(i)중 가장 작은 값 D(i)이다
        cout << dq.front().first;
    }
}
