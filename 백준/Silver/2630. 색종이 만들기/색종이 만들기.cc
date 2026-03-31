#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int paper[128][128];
int white, blue;

void color_paper(int sy, int sx, int gap){
    int temp=0;
    for(int i=sy; i<sy+gap; i++){
        for(int j=sx; j<sx+gap; j++){
            temp += paper[i][j];
        }
    }

    if(temp == 0){
        white++;
        return;
    }
    else if(temp == gap*gap){
        blue++;
        return;
    }

    int new_gap = gap / 2;
    color_paper(sy, sx, new_gap);
    color_paper(sy, sx+new_gap, new_gap);
    color_paper(sy+new_gap, sx, new_gap);
    color_paper(sy+new_gap, sx+new_gap, new_gap);
}


int main(){
    FAST_IO;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> paper[i][j];
        }
    }
    color_paper(0, 0, n);
    
    cout << white << '\n' << blue << '\n';
    return 0;
}