#include <string>
#include <vector>

using namespace std;

void dfs(int index, int sum, vector<int>& numbers, int target, int& answer){
    if(index == numbers.size()){
        if(sum == target) answer++;
        return;
    }
    dfs(index+1, sum+numbers[index], numbers, target, answer);
    dfs(index+1, sum-numbers[index], numbers, target, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(0, 0, numbers, target, answer);
    
    return answer;
}