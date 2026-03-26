#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    FAST_IO;
    int a, b;
    cin >> a >> b;
    // 유클리드 알고리즘
    int big = max(a, b);
    int small = min(a, b);
    int remainder = 0;
    while(small != 0){
        remainder = big % small;
        big = small;
        small = remainder;
    }
    int gcd = big;
    cout << gcd << '\n';

    // 최소 공배수 출력
    cout << (a/gcd) * b << '\n'; 

    return 0;
}