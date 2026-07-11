#include <iostream>
#include <vector>

using namespace std;
int g_inversion = 0;

void merge_sort(int list[], int left, int right);
void merge(int list[], int left, int mid, int right);
//N개의 정수가 주어졌을 때 역전수(버블정렬로 정렬했을 때 스왑 횟수)를 구하는 프로그램
//020과 동일하고 merge함수에서 큰 배열이 먼저 정렬되는 경우에만 역전수가 추가된다는 아이디어를 사용
//merge에서 역전수를 세는 단 한 줄만 추가 되었다.
int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	merge_sort(&v[0], 0, N - 1);  //병합 정렬을 사용
	cout << g_inversion;
	return 0;
}
//병합 정렬 만드는 방법!
//1. 분할 배열의 크기가 1이 될 때까지 계속 분할 한다
//2. 분할한 두 배열을 합병 한다
void merge_sort(int list[], int left, int right) {
	if (right <= left) { return; }
	int mid = (left + right) / 2;
	merge_sort(list, left, mid);
	merge_sort(list, mid + 1, right);
	merge(list, left, mid, right);
}
//분할 배열을 하나의 정렬된 배열로 만드는 방법!
//1. 투포인터(i, j)로 두 배열을 스캔하며 i값과 j값 중 작은 것을 정렬 배열에 정렬한다
//2. 투 포인터가 하나라도 분할 배열의 범위를 벗어나면 1을 종료
//3. 남은 분할 배열의 뒷부분을 정렬 배열에 복붙 한다
void merge(int list[], int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = 0;
	vector<int> sorted(right - left + 1);
	while (i <= mid && j <= right) {
		if (list[i] < list[j]) {
			sorted[k++] = list[i++];
		}
		else {
      //020에서 추가한 내용
			g_inversion += j - (left + k);
			sorted[k++] = list[j++];
		}
	}
	while (i <= mid) {
		sorted[k++] = list[i++];
	}
	while (j <= right) {
      //020에서 추가한 내용
		g_inversion += j - (left + k);
		sorted[k++] = list[j++];
	}
	for (int t = 0; t < k; t++) {
		list[left + t] = sorted[t];
	}
}
