#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, string>& now, const pair<int, string>& last) {
    return now.first < last.first;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, string>> vp(n);
    
    for(int i=0; i<n; i++) {
        int a;
        string b;
        cin >> a >> b;
        vp[i] = {a, b};
    }

    stable_sort(vp.begin(), vp.end(), cmp);
    for (auto x: vp) cout << x.first << ' ' << x.second << '\n'; 
    return 0;
}