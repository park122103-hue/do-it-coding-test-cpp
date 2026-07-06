#include <iostream>

using namespace std;
//수열 A(i)를 A(start)부터 A(end)까지 더한 값(구간합)을 구하는 프로그램
int main() {
    int N, M, start, end;  //수열 길이, 질의의 수, start 인덱스, end 인덱스
    int temp = 0;
    cin >> N >> M;
    //초기 조건 S(0)=0
    int S[100001] = { 0 };
    //관계식 S(i)=A(i)+S(i-1)
    for (int i = 1; i <= N; i++) {
        cin >> temp;  //temp=A(i)
        S[i] = temp + S[i - 1];
    }
    //관계식 result=S(start)-S(end-1)
    int result[100001];
    for (int i = 1; i <= M; i++) {
        cin >> start >> end;
        result[i] = S[end] - S[start - 1];
    }
    
    for (int i = 1; i <= M; i++) {
        cout << result[i] << '\n';
    }
}
