#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    FAST_IO;
    int n;
    cin >> n;
    int arr[1005];
    arr[0]=1, arr[1]=1;
    for(int i=2; i<=n; i++){
        arr[i] = (arr[i-1] + arr[i-2]) % 10007;
    }
    cout << arr[n] << '\n';
    return 0;
}