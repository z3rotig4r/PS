#include <bits/stdc++.h>
using namespace std;

int n, x;
string cmd;
queue<int> q;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> x;
            q.push(x);
        }
        else if (cmd == "pop") {
            if (q.size() == 0) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (cmd == "size") {
            cout << q.size() << '\n';
        }
        else if (cmd == "empty") {
            if (q.size() == 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (cmd == "front") {
            if (q.size() == 0) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else if (cmd == "back") {
            if (q.size() == 0) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }
    return 0;
}