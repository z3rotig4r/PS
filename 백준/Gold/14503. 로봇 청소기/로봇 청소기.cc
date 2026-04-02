#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int map_2d[50][50];

int main(){
    FAST_IO;
    int n, m, r, c, d;
    cin >> n >> m;
    cin >> r >> c >> d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map_2d[i][j];
        }
    }
    int result = 0;
    int sy = r;
    int sx = c;
    while(true){
        if(map_2d[sy][sx] == 0){
            map_2d[sy][sx] = -1; // 청소한 칸을 -1로 변경
            result++;
        }
        bool moved = false;
        for(int i=0; i<4; i++){
            d = (d+3)%4;
            int ny = sy + dy[d]; 
            int nx = sx + dx[d];
            if(ny>=0 && nx>=0 && ny<n && nx<m && map_2d[ny][nx] == 0){
                sx = nx;
                sy = ny;
                moved = true;
                break;
            }
        }
        if(!moved){
            // 빈 칸이 없을 때의 후진 case 정리
            int back_d = (d+2) % 4;
            int ny = sy + dy[back_d];
            int nx = sx + dx[back_d];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || map_2d[ny][nx] == 1) break;
            sy = ny;
            sx = nx;
        }
    }
    
    cout << result << '\n';
    
    return 0;
}