#include <bits/stdc++.h>
using namespace std;

int arr[26];

int main(){
    string s;
    cin >> s;
    int str_len = s.length();

    for(int i=0; i<26; i++){
        arr[i] = 0;
    }

    for(int i=0; i<str_len; i++){
        arr[char(s[i]) - 'a'] += 1;
    }

    for (int x : arr) cout << x << " ";

    return 0;
}