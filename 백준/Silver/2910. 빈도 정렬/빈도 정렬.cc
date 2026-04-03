#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    FAST_IO;
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> v;
    map<int, int> mp, mp_first;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        mp[num]++;
        if(mp_first[num] == 0) mp_first[num] = i+1;
    }
    for(auto it : mp){
        v.push_back({it.second, it.first});
    }
    sort(v.begin(), v.end(), [&](const pair<int, int>& a, const pair<int, int>& b){
        if(a.first == b.first) return mp_first[a.second] < mp_first[b.second];
        return a.first > b.first;
    });
    for(auto i : v){
        for(int j=0; j<i.first; j++){
            cout << i.second << " ";
        }
    }
    return 0;
}