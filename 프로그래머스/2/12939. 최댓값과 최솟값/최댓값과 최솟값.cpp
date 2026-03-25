#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split(const string& input, string delimiter){
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimiter);
    while(end != string::npos){
        result.push_back(input.substr(start, end-start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    result.push_back(input.substr(start));
    return result;
}

string solution(string s) {
    string answer = "";
    vector<int> v_i;
    vector<string> s_strings = split(s, " ");
    for(const string& s : s_strings){
        v_i.push_back(stoi(s));
    }
    sort(v_i.begin(), v_i.end());
    answer += to_string(v_i.front());
    answer += " ";
    answer += to_string(v_i.back());
    return answer;
}