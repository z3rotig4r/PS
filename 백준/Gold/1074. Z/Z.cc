#include <bits/stdc++.h>
#define FAST_IO sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int zCalculator(int y, int x, int size){
    if(size == 1) return 0;
    int result = 0;
    int new_size = size/2;
    int gap = (size*size)/4;
    if(y >= new_size && x >= new_size){
        result += gap*3;
        y -= new_size; x -= new_size;
    }
    else if(y >= new_size && x < new_size){
        result += gap*2;
        y -= new_size;
    }
    else if(y < new_size && x >= new_size){
        result += gap;
        x -= new_size;
    }
    return result + zCalculator(y, x, new_size);
}

int main() {
    int n, r, c;
    int result;
    cin >> n >> r >> c;
    int size = pow(2, n);
    // 한 변만 size로 넘기기
    result = zCalculator(r, c, size);

    cout << result << '\n';

    return 0;
}