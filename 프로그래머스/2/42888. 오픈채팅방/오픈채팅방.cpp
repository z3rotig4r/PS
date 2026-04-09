#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> uid_nn;
    vector<pair<string, string>> events;
    
    for(string s : record){
        stringstream ss(s);
        string cmd, uid, nn;
        
        ss >> cmd >> uid;
        if(cmd == "Enter" || cmd == "Change"){
            ss >> nn;
            uid_nn[uid] = nn;
        }
        if(cmd == "Enter" || cmd == "Leave"){
            events.push_back({cmd, uid});
        }
    }
    for(auto event : events){
        string cmd = event.first;
        string uid = event.second;
        string final_nn = uid_nn[uid];
        if(cmd == "Enter") answer.push_back(final_nn + "님이 들어왔습니다.");
        else if(cmd == "Leave") answer.push_back(final_nn + "님이 나갔습니다.");
    }
    return answer;
}