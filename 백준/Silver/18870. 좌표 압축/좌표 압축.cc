#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    FAST_IO;
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> cv(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
        cv[i] = v[i];
    }
    sort(cv.begin(), cv.end()); // O(nlogn)
    cv.erase(unique(cv.begin(), cv.end()), cv.end()); // O(n)
    for(int i=0; i<n; i++){
        int rank = lower_bound(cv.begin(), cv.end(), v[i]) - cv.begin();
        cout << rank << ' ';
    }
    cout << '\n';
    return 0;
}