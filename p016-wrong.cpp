#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;   // 수열 길이

    vector<int> A(n);               // 수열

    for (int i = 0; i < n; i++) {   // 수열 입력
        cin >> A[i];
    }

    int count = n;
    int lager = A[n - 1];
    for (int i = n - 1; i > 0; i--) {
        if (lager < A[i - 1]) {
            lager = A[i - 1];
            count--;
        }
    }

    cout << count << '\n';
}
