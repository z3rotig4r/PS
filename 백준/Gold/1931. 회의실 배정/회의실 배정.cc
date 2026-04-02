#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    FAST_IO;
    int n;

    cin >> n;
    vector<pair<int, int>> vp(n);
    for(int i=0; i<n; i++){
        cin >> vp[i].first >> vp[i].second;
    }
    sort(vp.begin(), vp.end(), cmp);

    int result = 0;
    int current_time = 0;
    for(auto& x: vp){
        if(x.first >= current_time){
            result++;
            current_time = x.second;
        }
    }

    cout << result << '\n';
    
    return 0;
}