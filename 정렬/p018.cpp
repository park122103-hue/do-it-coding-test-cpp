#include <iostream>
#include <vector>

using namespace std;
//각 사람이 돈을 인출하는데 걸린 시간의 합을 구하는 프로그램
int main() {
    int N;    //사람의 수
    cin >> N;
    vector<int> P(N + 1);   //i번째 사람이 돈을 인출하는데 걸리는 시간 P(i)
    //각 사람이 돈을 인출하는데 걸리는 시간을 삽입 정렬로 오름차순 정렬한다
    for (int i = 0; i < N; i++) {  //i에 삽입
        int now;
        cin >> now;     //삽입할 값

        int key = 0;    //삽입할 위치
        for (; key < i && P[key] > now; key++);  //삽입할 위치는 삽입할 값보다 큰 값이 되는 위치
        for (int j = i; j > key; j--) {  //정렬 구간은 0부터 i-1까지
           P[j] = P[j - 1];
        }
        P[key] = now;  //삽입할 위치에 삽입
    }
    
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cout << P[i] << ' ';
        sum += P[i] * N;
    }
    cout << sum << '\n';
}
