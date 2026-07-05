#include <iostream>
#include <vector>

using namespace std;
//문자열이 주어졋을 때 이를 수열로 변환하고 수열의 합을 구하는 프로그램
int main() {
    int n;    //수열 길이
    string str;    //문자열(수열)
    cin >> n;
    cin >> str;
    int A[100];
    //입력받은 문자열(수열)을 숫자로 변환해서 배열 A[i]에 저장
    for (int i = 0; i < n; i++) {
        A[i] = str[i] - '0';
    }
    //구간합 수열 S[i] 정의
    int S[100];
    //점화식의 초기 조건 S[0]=A[0]
    S[0] = A[0];
    //점화식의 관계 식 S[i]=A[i]+S[i-1]
    for (int i = 1; i < n; i++) {
        S[i] = A[i] + S[i - 1];
    }
    cout << S[n - 1];
}
