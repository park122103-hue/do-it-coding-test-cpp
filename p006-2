#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, count;
    count = 0;

    cin >> N;
    for (int q = 1; q <= sqrt(2 * N + 9 / 4) + 3 / 2; q++) {
        int A = N / q + 1;
        int B = (q - 1) / 2;
        int tmp = (A + B) * (A + B + 1) / 2 - (A + B - q + 1) * (A + B - q) / 2;
        if (A + B - q + 1 >= 1) {
            for (; tmp > N; A--) {
                tmp = (A + B) * (A + B + 1) / 2 - (A + B - q + 1) * (A + B - q) / 2;
            }
            if (tmp == N) count++;
        }
    }

    cout << count;
}
