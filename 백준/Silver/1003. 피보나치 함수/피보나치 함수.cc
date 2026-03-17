#include <bits/stdc++.h>
using namespace std;

int fibo[41] = {0, 1, 1};

int fibonacci(int n) {
    if (n<=2 || fibo[n] != 0) return fibo[n];
    fibo[n] = fibonacci(n-1) + fibonacci(n-2);
    return fibo[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n;
        if (n == 0) {
            cout << "1 0\n";
            continue;
        }
        cout << fibonacci(n-1) << ' ' << fibonacci(n) << '\n';
    }
    return 0;
}