#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int max_int = 100005;
int s_arr[max_int];
// 0 

int main(){
    FAST_IO;
    int n, m;
    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        int temp;
        cin >> temp;
        s_arr[i] = temp + s_arr[i-1];
    }
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        cout << s_arr[b] - s_arr[a-1] << '\n';
    }

    return 0;
}