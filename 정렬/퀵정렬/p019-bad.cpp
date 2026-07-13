#include <iostream>
#include <vector>

using namespace std;

void quick_sort(int list[], int left, int right, int K);
int partition(int list[], int left, int right);

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	quick_sort(&v[0], 0, N - 1, K);
	for (int i = 0; i < N; i++) {
		cout << v[i] << ' ';
	}
	cout << '\n' << v[K];
}

void quick_sort(int list[], int left, int right, int K) {
	//집합 크기가 1 이상일 때
	if (right > left) {
		//pivot을 기준으로 작은 값 집합과 큰 값 집합으로 나눈다
		int pivot = partition(list, left, right);
		if (pivot == K - 1) return;
		//작은 값 집합과 큰 값 집합 집합을 정렬 한다
		if (pivot - 1 > left) quick_sort(list, left, pivot - 1, K);
		if (pivot + 1 < right) quick_sort(list, pivot + 1, right, K);
	}
	return;
}


int partition(int list[], int left, int right) {
	int start = left;
	int end = right - 1;
	int pivot = right;
	if (right - left == 0) {
		return right;
	} else if (right - left == 1) {
		if (list[left] > list[right]) 
			swap(list[left], list[right]);
		return right;
	}
	while (start <= end) {
		while (start <= end && list[start] < list[pivot])
			start++;
		while (start <= end && list[end] >= list[pivot])
			end--;
		if (start < end) swap(list[start++], list[end--]);
	}
	if (list[start] >= list[pivot])
		pivot = start;
	else if (list[end] >= list[pivot])
		pivot = end;
	swap(list[pivot], list[right]);
	return pivot;
}
