#include <iostream>
#include <vector>

using namespace std;
//수열 A(i)를 A(i)부터 A(j)까지 더한 값이 M으로 나누어 떨어지는 (i,j) 쌍의 갯수를 구하는 프로그램
int main() {
    int tmp;
    int N, M;    //수열 길이, 질의의 수
    cin >> N >> M;
    vector<int> S(N + 1);    //구간합을 M으로 나눈 나머지의 배열 S(i)
    vector<int> L(M);    //나머지가 q인 경우의 수 L(q)
    //나머지 S(i)를 구하고, 경우의 수 L(S(i))에 1을 더한다
    for (int i = 1; i <= N; i++) {
        cin >> tmp;    //tmp=A(i)
        S[i] = (tmp + S[i - 1]) % M;
        L[S[i]]++;
    }
    
    long long count = 0;
    count += L[0];
    //나머지가 q인 구간합 S(i)는 L(q)개 있다
    //S(i)-S(j)=0므로 L(q)개중 2개를 무작위로 뽑는 조합의 수는 L(q)x(L(q)-1)/2
    for (int i = 0; i < M; i++) {
        if (L[i] > 0) count += 1LL * L[i] * (L[i] - 1) / 2;
    }
    cout << count << '\n';
}
