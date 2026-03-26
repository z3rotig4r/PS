#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

bool isPrime(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0) return false;
    }
    return true;
}

int main(){
    FAST_IO;
    
    int n;
    cin >> n;
    int cnt = 0;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        if(tmp == 1){
            continue;
        }
        if(isPrime(tmp)) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}