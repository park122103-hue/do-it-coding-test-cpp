#include <iostream>

using namespace std;

int main() {
    int N;
    int count = 0;
    int sum = 1;
    int start = 1;
    int end = 1;

    cin >> N;
    while (start <= N) {
        while (sum <= N) {
            if (sum == N) count++;
            end++;
            sum += end;
        }
        while (sum > N) {
            start++;
            sum -= start - 1;
        }
    }

    cout << count;
}
