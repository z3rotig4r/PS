#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

bool isPrime(int num){
    if(num < 2) return false;
    for(int i=2; i<=sqrt(num); i++){
        if(num%i==0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int> unique_nums;
    sort(numbers.begin(), numbers.end());
    do{
        for(int i=1; i<=numbers.size(); i++){
            int num = stoi(numbers.substr(0, i));
            unique_nums.insert(num);
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    for(int num : unique_nums){
        if(isPrime(num)) answer++;
    }
    return answer;
}