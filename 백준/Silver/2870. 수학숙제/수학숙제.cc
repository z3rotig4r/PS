#include <bits/stdc++.h>
using namespace std;

void go(vector<string>& vs, string& result){
    while(true){
        if(result.size() && result.front() == '0') result.erase(result.begin());
        else break;
    }
    if(result.size() == 0) result = "0";
    vs.push_back(result);
    result = "";
}

bool cmp(const string& a, const string& b){
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main(){
    // 97 ~ 122
    int n;
    cin >> n;
    vector<string> vs;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        string result = "";
        for(int j=0; j<str.size(); j++){
            if(str[j]<65) result += str[j];
            else if(result.size()) go(vs, result);
        }
        if(result.size()) go(vs, result);
    }
    sort(vs.begin(), vs.end(), cmp);
    for(auto& s : vs){
        cout << s << '\n';
    }
    return 0;
}