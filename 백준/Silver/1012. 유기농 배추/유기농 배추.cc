#include <bits/stdc++.h>
using namespace std;

const int MAX_INT = 54;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int gmap[MAX_INT][MAX_INT], visited[MAX_INT][MAX_INT];
int m, n, k;
int cnt=0;

void dfs(int sy, int sx){
    visited[sy][sx] = 1;
    for(int i=0; i<4; i++){
        int ny = sy + dy[i];
        int nx = sx + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(gmap[ny][nx] && !visited[ny][nx]) {
            dfs(ny, nx);
        }
    }
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n >> k;
        // 전부 0으로 초기화
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                gmap[i][j] = 0;
                visited[i][j] = 0;
            }
        }
        // 배추가 심어진 "1" 위치만 입력받아 넣기
        int x, y;
        
        for(int i=0; i<k; i++){
            cin >> x >> y;
            gmap[y][x] = 1;
        }
        // cnt 변수와 dfs 활용해 지렁이 수 출력하기
        cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(gmap[i][j] == 1 && !visited[i][j]){
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}