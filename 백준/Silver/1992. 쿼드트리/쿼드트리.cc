#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int arr[64][64];

string quadTree(int y, int x, int sz){
    // 재귀 탈출 조건
    if(sz == 1) return string(1, arr[y][x]);
    char b = arr[y][x];
    string result = "";
    bool flag = 0;
    for(int i=y; i<y+sz; i++){
        for(int j=x; j<x+sz; j++){
            if(b != arr[i][j]){
                result += '(';
                result += quadTree(y, x, sz/2);
                result += quadTree(y, x+sz/2, sz/2);
                result += quadTree(y+sz/2, x, sz/2);
                result += quadTree(y+sz/2, x+sz/2, sz/2);
                result += ')';
                return result;
            }
        }
    }
    return string(1, arr[y][x]);
}

int main(){
    FAST_IO;
    string s;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<n; j++){
            arr[i][j] = s[j];
        }
    }

    cout << quadTree(0, 0, n) << '\n';

    return 0;
}