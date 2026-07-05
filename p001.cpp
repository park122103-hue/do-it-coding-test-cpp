#include <iostream>

using namespace namespace std;

int main() {
    int n;
    string str;
    cin >> n;
    cin >> str;
    int A[100];

    for (int i = 0; i < n; i++) {
        A[i] = str[i] - '0';
    }

    int S[100];
    S[0] = A[0];
    for (int i = 1; i < n; i++) {
        S[i] = A[i] + S[i - 1];
    }
    cout << S[n - 1];
}
