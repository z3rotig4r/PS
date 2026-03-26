#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    FAST_IO;
    int n, k;
    int result = 1;
    int divider = 1;
    cin >> n >> k;
    for(int i=n; i>n-k; i--) result *= i;
    for(int i=1; i<=k; i++) divider *= i;
    result = result/divider;
    cout << result << '\n';
    return 0;
}