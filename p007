#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;

    cin >> N;
    cin >> M;
    int count = 0;
    int start = 0;
    int end = N - 1;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    while (start < end) {
        while (A[start] + A[end] >= M) {
            if (A[start] + A[end] == M) count++;
            end--;
        }
        while (A[start] + A[end] < M) {
            start++;
        }
    }
    cout << count;
}
