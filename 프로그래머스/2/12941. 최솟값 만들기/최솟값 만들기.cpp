#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int length = A.size();
    sort(A.rbegin(), A.rend());
    sort(B.begin(), B.end());
    for(int i=0; i<length; i++){
        answer += A.back() * B.back();
        A.pop_back();
        B.pop_back();
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << answer << endl;

    return answer;
}