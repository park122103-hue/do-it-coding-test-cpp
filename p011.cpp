#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;
    int i = 1;
    vector<char> ch;
    stack<int> s;
    while (count < n) {
        int now;
        cin >> now;
        while (i <= now) {
            s.push(i++);
            ch.push_back('+');
        }
        if (s.top() == now) {
            s.pop();
            ch.push_back('-');
            count++;
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }

    for (int k = 0; k < ch.size(); k++) {
        cout << ch[k] << '\n';
    }
}
