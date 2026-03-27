#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    FAST_IO;
    int t;
    cin >> t;
    // 1: 1 || 2: 2 || 3: 4(=1+2+1) || 4: 7(=1+3+2+1) || 5: 13(=1+4+3+3+2)
    int dp[11]={1, 2, 4};
    for(int i=3; i<11; i++) dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        cout << dp[n-1] << '\n';
    }
    
    return 0;
}