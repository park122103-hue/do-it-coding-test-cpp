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
	quick_sort(v, 0, N - 1);
	for (int i = 0; i < N; i++) {
		cout << v[i] << ' ';
	}
	cout << '\n' << v[K];
}

void quick_sort(vector<int>& vec, int left, int right) {
	if (right <= left) return;
	int p = partition(vec, left, right);
	quick_sort(vec, left, p);
	quick_sort(vec, p + 1, right);
}


int partition(vector<int>& vec, int left, int right) {
	int pivot = vec[right];
	int i = left - 1;
	int j = right + 1;

	while (1) {
		//크거나 같은 것이 나오면 정지
		do {
			i++;
		} while (vec[i] < pivot);
		//작거나 같은 것이 나오면 정지
		do {
			j--;
		} while (vec[j] > pivot);
		//정렬이 완료 되었다면 j이하의 값들은 pivot보다 작으므로 j를 반환한다 그렇지 않다면...
		if (j <= i) return j;
		swap(vec[i], vec[j]);	//작거나 같은 것을 왼쪽(j)으로, 크거나 같은 것을 오른쪽(i)으로
	}
}
