#include <iostream>
#include <deque>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	deque<int> dq;
	vector<int> ans;
	for (int i = 0; i < n; i++) {
	    int x;
	    cin >> x;
	
	    if (x != 0) {
	        dq.push_back(x);
	        int tmp = dq.size();
	        int root = tmp - 1;
	        int parent = tmp / 2 - 1;
	        while (parent >= 0 && ((abs(dq[parent]) > abs(x)) || (abs(dq[parent]) == abs(x) && dq[parent] > x))) {
	            dq[root] = dq[parent];
	            dq[parent] = x;
	            tmp /= 2;
	            root = tmp - 1;
	            parent = tmp / 2 - 1;
	        }
	    }
	    else {
	
	        if (dq.size() != 0) {
	            ans.push_back(dq.front());
	            dq.pop_front();
	            if (dq.size() > 1) {
	                if ((abs(dq[0]) > abs(dq[1])) || (abs(dq[0]) == abs(dq[1]) && dq[0] > dq[1])) {
	                    int a = dq[0];
	                    dq[0] = dq[1];
	                    dq[1] = a;
	                }
	            }
	        }
	        else {
	            ans.push_back(0);
	        }
	    }
	}
	
	for (int i = 0; i < ans.size(); i++) {
	    cout << ans[i] << '\n';
	}
}
