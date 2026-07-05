#include <iostream>
#include <vector>
#include <algorithm>  //swap함수

using namespace std;

int main() {
    int n;
    cin >> n;   //수열 길이

    vector<int> A(n);               //수열
		//수열 입력
    for (int i = 0; i < n; i++) {   
        cin >> A[i];
    }
    //버블 정렬
    for (int i = 0; i < n - 1; i++) {   //구간(0~n-1) ~ 구간(n-2~n-1)까지
        for (int j = n - 1; j > i; j--) {   //구간 (i~n-1)에서 차례대로
            if (A[j] < A[j - 1]) {          //swap조건을 만족하면 swap한다
                swap(A[j], A[j - 1]);
            }
        }

    }
    //정렬 완료
    for (int i = 0; i < n; i++) {
        cout << A[i] << '\n';
    }
}
