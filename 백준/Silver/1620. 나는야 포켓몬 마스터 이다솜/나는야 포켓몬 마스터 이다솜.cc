#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    FAST_IO;
    int n, m;
    unordered_map<string, int> um;
    string arr[100001];
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        um.insert(make_pair(str, i+1));
        arr[i+1] = str;
    }
    for(int i=0; i<m; i++){
        string input;
        cin >> input;
        if(isdigit(input[0])) cout << arr[stoi(input)] << '\n';
        else cout << um[input] << '\n';
    }
    return 0;
}