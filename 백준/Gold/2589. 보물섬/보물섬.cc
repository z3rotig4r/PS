#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
// 1칸에 1시간

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int maps[50][50];
int visited[50][50];

int bfs(int y, int x, const int h, const int w){
    queue<pair<int, int>> q;
    int maxi=0;
    q.push({y, x});
    visited[y][x] = 1;
    while(!q.empty()){
        int sy = q.front().first;
        int sx = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int ny = sy + dy[i];
            int nx = sx + dx[i];
            if(ny<0 || nx<0 || ny>=h || nx>= w) continue;
            if(maps[ny][nx] == 0 || visited[ny][nx] != 0) continue;
            visited[ny][nx] = visited[sy][sx] + 1;
            if(visited[ny][nx] > maxi) maxi = visited[ny][nx];
            q.push({ny, nx});
        }
    }
    return maxi-1;
}

int main(){
    int h, w;
    int result=0;
    cin >> h >> w;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            char c;
            cin >> c;
            if(c == 'W') maps[i][j] = 0;
            else if (c == 'L') maps[i][j] = 1;
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(maps[i][j] == 1){
                memset(visited, 0, sizeof(visited));
                int ret = bfs(i, j, h, w);
                if(ret > result) result = ret;
            }
        }
    }
    cout << result << '\n';
    return 0;
}