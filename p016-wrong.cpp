#include <iostream>
#include <vector>

using namespace std;
//버블정렬의 정렬 횟수+1을 구하는 프로그램... 을 만드려고 했으나
//아마도 이건 선택 정렬의 정렬 횟수+1을 구하는 프로그램인 듯 하다
//정확히는 n부터 1까지 스캔한다음 최댓값을 n으로 보내는 선택정렬의 swap 횟수
int main() {
    int n;
    cin >> n;   // 수열 길이

    vector<int> A(n);               // 수열

    for (int i = 0; i < n; i++) {   // 수열 입력
        cin >> A[i];
    }

    int count = n;
    int larger = A[n - 1];
    for (int i = n - 1; i > 0; i--) {
        if (larger < A[i - 1]) {
            larger = A[i - 1];
            count--;
        }
    }

    cout << count << '\n';
}
