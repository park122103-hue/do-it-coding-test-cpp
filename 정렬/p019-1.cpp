#include <iostream>
#include <vector>

using namespace std;

void quick_sort(int* A, int left, int right);

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	quick_sort(&v[0], 0, N - 1);
	cout << v[K - 1];
}

void quick_sort(int *A, int left, int right) {
	if (right <= left) return;
	int start = left;
	int end = right-1;
	//집합 left to right
	//집합 시작 부터 집합 끝까지
	while (start <= end) {
		swap(A[start], A[end]);
		while (start <= end && A[start] < A[right]) {
			start++;
		}
		while (start <= end && A[end] >= A[right]) {
			end--;
		}
	}
	swap(A[start], A[right]);
	if (start - left > 1) quick_sort(A , left, start - 1);
	if (right - start > 1) quick_sort(A, start + 1, right);
}
