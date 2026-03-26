#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int s[21];

int main(){
    FAST_IO;
    int m;
    cin >> m;
    
    for(int i=0; i<m; i++){
        string cmd;
        cin >> cmd;
        if (cmd == "add"){
            int x;
            cin >> x;
            s[x] = 1;
        }
        else if (cmd == "remove"){
            int x;
            cin >> x;
            s[x] = 0;
        }
        else if (cmd == "check"){
            int x;
            cin >> x;
            if(s[x]) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (cmd == "toggle"){
            int x;
            cin >> x;
            if(s[x]) s[x] = 0;
            else s[x] = 1;
        }
        else if (cmd == "all"){
            for(int j=1; j<21; j++){
                s[j] = 1;
            }
        }
        else if (cmd == "empty"){
            for(int j=1; j<21; j++){
                s[j] = 0;
            }
        }
    }

    return 0;
}