#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> coord_v;

int main() {
    int n, x, y;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x >> y;
        coord_v.push_back(pair<int, int>(x, y));
    }

    sort(coord_v.begin(), coord_v.end());

    for (pair<int, int> x : coord_v)
        cout << x.first << " " << x.second << '\n';

    return 0;
}