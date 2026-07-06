#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//N개의 수중 좋은 수의 갯수 구하기
//좋은 수: N개의 수중 다른 두 수의 합이 될 수 있는 수
int main() {
    int N;

    cin >> N;
    int count = 0;
    int start = 0;
    int end = N - 1;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    for (int i = 0; i < N; i++) {
        int start = 0;
        int end = N - 1;
        while (start < end) {
            if (A[start] + A[end] > A[i]) {
                end--;
            }
            else if (A[start] + A[end] < A[i]) {
                start++;
            }
            else if (A[start] + A[end] == A[i]) {
                count++;
                break;
            }
        }
    }

    cout << count;
}
