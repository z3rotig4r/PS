#include <bits/stdc++.h>
using namespace std;

int arr[9];
vector<int> v;
int all_sum = 0;
pair<int, int> ret;

void solve() {
    for(int i=0; i<9; i++) {
        for(int j=i+1; j<9; j++){
            if(all_sum - arr[i] - arr[j] == 100){
                ret = {i, j};
                return;
            }
        }
    }
}


int main(){
    for (int i=0; i<9; i++) {
        cin >> arr[i];
        all_sum += arr[i];
    }
    solve();
    for(int i=0; i<9; i++){
        if(ret.first == i || ret.second == i) continue;
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());
    for (int i : v) cout << i << "\n";
    return 0;
}