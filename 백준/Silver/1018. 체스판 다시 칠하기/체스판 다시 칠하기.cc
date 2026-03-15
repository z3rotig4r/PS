#include <bits/stdc++.h>
using namespace std;

string WB[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

string BW[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

int n, m;
string temp;
vector<string> input;

int cnt_wb(int x, int y) {
    int cnt = 0;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if(input[x+i][y+j] != WB[i][j]) cnt++;
        }
    }
    return cnt;
}

int cnt_bw(int x, int y) {
    int cnt = 0;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if(input[x+i][y+j] != BW[i][j]) cnt++;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> temp;
        input.push_back(temp);
    }
    int min_repaint = 65;

    for (int i=0; i<=n-8; i++){
        for (int j=0; j<=m-8; j++){
            int tmp = min(cnt_wb(i, j), cnt_bw(i, j));
            if (tmp < min_repaint) min_repaint = tmp;
        }
    }
    cout << min_repaint;
    return 0;
}