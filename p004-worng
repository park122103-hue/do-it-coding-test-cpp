#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, A[1000];
    double sum = 0;
    int max = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sum += A[i];
        if (A[i] > max) max = A[i];
    }

    double result = sum * 100.0 / max / n;
    cout << result;
}
