#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int length = progresses.size();
    for(int i=0; i<length; i++){
        q.push((100 - progresses[i] + speeds[i] - 1)/speeds[i]);
    }
    while(!q.empty()){
        int cnt = 1;
        int temp = q.front();
        q.pop();
        while(q.front() <= temp && !q.empty()){
            q.pop();
            cnt++;
        }
        if (cnt != 0) answer.push_back(cnt);
    }
    
    return answer;
}