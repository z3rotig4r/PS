#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

bool isVowel(int idx){
    return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

int main(){
    FAST_IO;
    while(true){
        string str;
        cin >> str;
        bool flag=0, is_include_v=0;
        int prev = -1;
        if(str == "end") break;
        int lcnt=0; // 모음
        int vcnt=0; // 자음
        for(int i=0; i<str.size(); i++){
            int idx = str[i];
            if(isVowel(idx)) lcnt++, vcnt=0, is_include_v=1;
            else vcnt++, lcnt=0;
            if(vcnt == 3 || lcnt == 3) flag=1;
            if(i>=1 && (prev==idx) && (idx != 'e' && idx != 'o')) flag=1;
            prev=idx;
        }
        if(is_include_v==0) flag=1;
        if(flag) cout << "<" << str << ">" << " is not acceptable.\n";
        else cout << "<" << str << ">" << " is acceptable.\n";   
    }
    return 0;
}