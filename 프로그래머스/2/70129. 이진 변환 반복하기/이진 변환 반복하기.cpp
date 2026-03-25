#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    int cnt = 0, zeros = 0;
    
    while(s != "1"){
        int current_zeros = 0;
        
        for(char x : s){
            if(x == '0') current_zeros++;
        }

        zeros += current_zeros;
        
        int c = s.length() - current_zeros;
        
        // 길이 c를 이진수 문자열로 변환
        string new_s = "";
        while(c > 0){
            new_s += to_string(c % 2);
            c /= 2;
        }
        
        // 구한 이진수를 뒤집어서 정상적인 이진수로
        reverse(new_s.begin(), new_s.end());
        s = new_s;
        cnt++;
    }
    
    return {cnt, zeros};
}