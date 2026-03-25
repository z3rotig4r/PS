#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int area = (brown+yellow);
    for(int i=1; i<=sqrt(area); i++){
        if(area % i == 0){
            int width = area / i;
            int height = i;
            if(2*(width+height)-4 == brown){
                return {width, height};
            }
        }
    }
}