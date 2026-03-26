#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int main(){
    FAST_IO;
    while(1){
        string str;
        cin >> str;
        if(str == "0") break;
        // 팰린드롬수인지 체크
        int length = str.size();
        bool isPalindrome = true;
        for(int i=0; i<length/2; i++){
            if(str[i] != str[length - 1 - i]){
                isPalindrome = false;
                break;
            }
        }
        if(isPalindrome){
            cout << "yes" << '\n';
        }
        else{
            cout << "no" << '\n';
        }     
    }
    

    return 0;
}