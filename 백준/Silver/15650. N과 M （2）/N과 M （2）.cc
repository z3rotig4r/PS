#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n, m;

void combi(int start, vector<int>& v){
    if(v.size() == m){
        for(int i : v) cout << i << " ";
        cout << '\n';
        return;
    }
    for(int i=start+1; i<=n-(m - v.size()) + 1; i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}

int main(){
    cin >> n >> m;
    vector<int> v;
    combi(0, v);
    return 0;
}