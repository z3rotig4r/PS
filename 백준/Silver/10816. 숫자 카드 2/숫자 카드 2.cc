#include <bits/stdc++.h>
#define GAP 10000000
using namespace std;

int arr[20000000];


// 0에 -10,000,000
// 10,000,000에 0
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, temp;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> temp;
        arr[temp+GAP]++;
    }
    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> temp;
        cout << arr[temp+GAP] << ' ';
    }
    return 0;
}