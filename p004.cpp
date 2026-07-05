#include <iostream>
#include <vector>    //벡터 자료형

using namespace std;

int main() {
    int tmp;
    int N, M;    //2차원 정사각 수열의 길이(NxN), 질의의 수
    vector<vector<int>> S(1025, vector<int>(1025));    //직사각형(x<i, y<j) 구간 내 수열의 구간합
    cin >> N >> M;
    //초기 조건 대신 S(0,y)=S(x,0)=0이다
    //관계식  S(x,y)=A(x,y)+S(x,y-1)+S(x-1,y)-S(x-1,y-1)
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            cin >> tmp;    //tmp=A(x,y)이다
            S[x][y] = tmp + S[x][y - 1] + S[x - 1][y] - S[x - 1][y - 1];
        }
    }
    //질의: 직사각형(x1<=x<=x2, y1<=y<=y2) 구간 내 수열의 합을 구하라
    //답: ANS=S(x2,y2)-S(x2,y2-y1)-S(x2-x1,y2)+S(x2-x1,y2-y1)
    int x1, y1, x2, y2;
    for (int i = 1; i <= M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << S[x2][y2] - S[x2][y1 - 1] - S[x1 - 1][y2] + S[x1 - 1][y1 - 1] << '\n';
    }
}
