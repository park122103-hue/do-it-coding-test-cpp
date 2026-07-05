#include <iostream>
#include <vector>
#include <algorithm>  //for pair, sort

using namespace std;

int main() {
    int n;
    cin >> n;   //수열 길이

    vector<pair<int, int>> A(n);               //수열

    for (int i = 0; i < n; i++) {   //수열 입력
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());
    int max = A[0].second;
    for (int i = 1; i < n; i++) {
        if (max < A[i].second - i) {
            max = A[i].second - i;
        }
    }

    cout << max + 1 << '\n';
}
