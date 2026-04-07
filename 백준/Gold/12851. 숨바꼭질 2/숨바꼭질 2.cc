#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int dp[100004];
int cnt[100004];

int main(){
    FAST_IO;
    int n, k;
    cin >> n >> k;
    queue<int> q;
    fill(&dp[0], &dp[100003], 987654321);
    q.push(n);
    dp[n] = 0;
    cnt[n] = 1;
    while(!q.empty()){
        int sx = q.front();
        q.pop();
        int arr[3] = {sx-1, sx+1, sx*2};
        for(int nx: arr){
            if(nx<0 || nx>100003) continue;
            if(dp[nx] > dp[sx]+1){
                dp[nx] = dp[sx]+1;
                cnt[nx] = cnt[sx];
                q.push(nx);
            }
            else if(dp[nx] == dp[sx]+1) cnt[nx] += cnt[sx];
        }
    }
    cout << dp[k] << '\n' << cnt[k] << '\n';
    return 0;
}