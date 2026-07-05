#include <iostream>

using namespace std;

int main() {
    int tmp;
    int N, M;
    //틀린 이유: int의 1025x1025배열은 약 4MB로 visual studio의 실행 한계인 1MB를 초과한다
    int B[1025][1025] = { 0 };  //1차원 행 구간합
    int S[1025][1025] = { 0 };  //2차원 행렬 구간합

    cin >> N >> M;
    for (int x = 1; x <= N; x++) {              // 배열의 x번째 줄의 구간합 B 배열: B(x,y)=A(x,1)+...+A(x,y)
        for (int y = 1; y <= N; y++) {
            cin >> tmp;
            B[x][y] = tmp + B[x][y - 1];
        }
    }

    for (int y = 1; y <= N; y++) {              // (1,1)부터 (x,y)의 사각형 내의 구간합 S배열
        for (int x = 1; x <= N; x++) {
            S[x][y] = B[x][y] + S[x - 1][y];
        }
    }

    int x1, y1, x2, y2;
    for (int i = 1; i <= M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << S[x2][y2] - S[x2][y1 - 1] - S[x1 - 1][y2] + S[x1 - 1][y1 - 1] << '\n';
    }
}
