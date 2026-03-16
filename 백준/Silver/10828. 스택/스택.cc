#include <bits/stdc++.h>
using namespace std;

int n, x;
string cmd;
stack<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> x;
            s.push(x);
        }
        else if (cmd == "pop") {
            if (s.size() == 0) {
                cout << -1 << '\n';
            }
            else {
                cout << s.top() << '\n';
                s.pop();
            }
        }
        else if (cmd == "size") {
            cout << s.size() << '\n';
        }
        else if (cmd == "empty") {
            if (s.size() == 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (cmd == "top") {
            if (s.size() == 0) cout << -1 << '\n';
            else {
                cout << s.top() << '\n';
            }
        }
    }
}