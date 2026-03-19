#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int max_int = 1005;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, m;
int gmap[max_int][max_int], visited[max_int][max_int];

void bfs(int sy, int sx){
    queue<pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = 0;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(gmap[ny][nx] == 0 || visited[ny][nx] != -1) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }   
    return;
}


int main(){
    FAST_IO;
    int y, x;
    cin >> n >> m;
    // input & start coord 저장
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> gmap[i][j];
            visited[i][j] = -1;
            if(gmap[i][j] == 2){
                y = i;
                x = j;
            }
            else if(gmap[i][j] == 0){
                visited[i][j] = 0;
            }
        }
    }
    // bfs로 visited 계산 -> 최단거리
    bfs(y, x);
    // 출력
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}