#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    FAST_IO;
    while(1){
        int x, y, z;
        cin >> x >> y >> z;
        int sum = x*x + y*y + z*z;
        if (!sum) break;
        int c = max({x, y, z});
        if(2*c*c == sum) cout << "right" << '\n';
        else cout << "wrong" << '\n';        
    }

    return 0;
}