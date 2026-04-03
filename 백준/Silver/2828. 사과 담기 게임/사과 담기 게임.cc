#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    int m, n, j;
    cin >> n >> m;
    cin >> j;
    int start = 1;
    int end = m;
    int result=0;
    for(int i=0; i<j; i++){
        int x;
        cin >> x;
        if(x > end){
            result += x-end;
            end = x; start = x-m+1;
        }
        else if(x <= end && x >= start) continue;
        else{
            result += start-x;
            start = x; end = x+m-1;
        }
    }
    cout << result << '\n';
    return 0;
}