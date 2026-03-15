#include <bits/stdc++.h>
using namespace std;

int n, m, temp;
vector<int> a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());

    cin >> m;
    for(int i=0; i<m; i++){
        cin >> temp;
        cout << binary_search(a.begin(), a.end(), temp) << '\n';
    }
    return 0;
}