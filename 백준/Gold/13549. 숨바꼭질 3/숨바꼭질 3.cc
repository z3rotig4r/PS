#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

//0-1BFS 문제

int main(){
    FAST_IO;
    int n, k;
    int t=0;
    int dp[100001];
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    deque<int> dq;
    dq.push_back(n);
    dp[n] = 0;
    while(!dq.empty()){
        int sx = dq.front();
        dq.pop_front();
        // loop 탈출 조건
        if(sx == k){
            cout << dp[sx] << '\n';
            break;
        }
        // 순간이동
        int nx = sx * 2;
        if(nx >= 0 && nx <= 100000){
            if(dp[nx] == -1 || dp[nx] > dp[sx]){
                dp[nx] = dp[sx];
                dq.push_front(nx);
            }
        }
        // 걷기
        nx = sx + 1;
        if(nx >= 0 && nx <= 100000){
            if(dp[nx] == -1 || dp[nx] > dp[sx]){
                dp[nx] = dp[sx] + 1;
                dq.push_back(nx);
            }
        }
        nx = sx - 1;
        if(nx >= 0 && nx <= 100000){
            if(dp[nx] == -1 || dp[nx] > dp[sx]){
                dp[nx] = dp[sx] + 1;
                dq.push_back(nx);
            }
        }
    }
    return 0;
}