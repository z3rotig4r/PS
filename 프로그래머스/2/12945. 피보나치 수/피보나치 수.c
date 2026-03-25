#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int bb_num = 0;
    int b_num = 1;
    for(int i=2; i<=n; i++){
        answer = (bb_num + b_num) % 1234567;
        bb_num = b_num;
        b_num = answer;
    }
    return answer;
}