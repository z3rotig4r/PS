#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int i=0;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int answer = 0;
    
    int start = 0;
    int end = people.size() - 1;
    
    while(start <= end){
        if(people[start]+people[end] <= limit){
            start++;
        }
        end--;
        answer++;
    }
    
    return answer;
}