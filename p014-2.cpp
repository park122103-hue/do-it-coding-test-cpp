#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// compAbs: 부모가 우선도 높으면 0, k가 우선도 같거나 높으면 1을 반환
bool compAbs(int k, int parent) {
    if (abs(k) == abs(parent)) {
        return k < 0;
    }
    else {
        return abs(k) <= abs(parent);
    }
}

// heap_insert: k 입력시 힙 자동 up정렬
void heap_insert(vector<int>& A, int k) {
    if (A.empty()) A.push_back(0);   // 배열이 비어있다면 0번 인덱스를 0으로 채운다

    A.push_back(k);
    int i = A.size() - 1;
    while (i / 2 >= 1 && compAbs(A[i], A[i / 2])) { // 부모가 있고, 부모보다 k의 우선도가 높다면 부모와 자리를 바꾼다
        int tmp = A[i];
        A[i] = A[i / 2];
        A[i / 2] = tmp;
        i /= 2;
    }
}

// heap_delete: 힙의 root를 삭제 및 리턴하고, 힙의 맨 마지막 요소를 root로 이동한 뒤 down정렬
int heap_delete(vector<int>& A) {
    int root = A[1];
    A[1] = A.back();
    A.pop_back();

    int i = 1;
    while (2 * i <= A.size() - 1) { // 자식이 있다면
        int first_child;
        first_child = 2 * i;
        if (2 * i + 1 <= A.size() - 1) {
            if (!compAbs(A[2 * i], A[2 * i + 1])) {
                first_child = 2 * i + 1;
            }
        }

        if (compAbs(A[i], A[first_child])) {
            break;
        }
        else {
            int tmp = A[i];
            A[i] = A[first_child];
            A[first_child] = tmp;
            i = first_child;
        }
    }
    return root;
}

int main() {
    int n;
    cin >> n;

    vector<int> abs_heap(1);
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x == 0) {
            if (abs_heap.size() == 1) {
                ans.push_back(0);
            }
            else {
                ans.push_back(heap_delete(abs_heap));
            }
        }
        else {
            heap_insert(abs_heap, x);
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
}
