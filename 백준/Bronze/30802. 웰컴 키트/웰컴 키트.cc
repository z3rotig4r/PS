#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    FAST_IO;
    int n;
    int sum=0;
    int arr[6];
    cin >> n;
    for(int i=0; i<6; i++){
        cin >> arr[i];
    }
    int t, p;
    cin >> t >> p;
    for(int i=0; i<6; i++){
        if(arr[i] == 0) continue;
        sum += (arr[i]-1)/t + 1;
    }
    cout << sum << '\n';
    cout << n/p << ' ' << n%p << '\n';

    return 0;
}