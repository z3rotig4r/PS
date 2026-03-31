#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

int main() {
    int n;
    cin >> n;

    dp[1] = 0; // 1을 만드는 횟수는 0
    for (int i = 2; i <= n; i++) {
        // 1. 기본적으로 1을 빼는 경우 (i-1에서 왔다고 가정)
        dp[i] = dp[i - 1] + 1;

        // 2. 2로 나누어 떨어지는 경우
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);

        // 3. 3으로 나누어 떨어지는 경우
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    cout << dp[n] << '\n';
    return 0;
}