#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void radix_sort(int list[], int N, int k);
//N개의 자연수가 주어졌을 때 기수 정렬하는 프로그램
int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	radix_sort(&v[0], N, 5);  //병합 정렬을 사용
	for (int i = 0; i < N; i++) {
		cout << v[i] << '\n';
	}
	return 0;
}

//기수 정렬 만드는 방법
void radix_sort(int list[], int N, int k) {
	//자릿수 정렬을 위한 기수 큐
	vector<deque<int>> radix(10);
	//순서대로 넣는다
	int x = 1;
	for (int i = 0; i < k; i++) {	//1, 10, 100의 자리 순서대로 순회하며 정렬
		// 배열 순서대로 enque
		for (int n = 0; n < N; n++) {
			for (int t = 0; t < 10; t++) {
				if ((list[n]/x)%10 == t) {
					radix[t].push_back(list[n]);
					break;
				}
			}
		}
		// 기수 순서대로 deque
		for (int n = 0, t = 0; n < N && t < 10; t++) {
			while (!radix[t].empty()) {
				list[n++] = radix[t].front();
				radix[t].pop_front();
			}
		}

		x *= 10;
	}
}
