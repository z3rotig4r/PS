#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
char maps[1000][1000];
int visited[1000][1000];
int fire_time[1000][1000];

int r, c;

int bfs(int y, int x){
    queue<pair<int, int>> q;
    q.push({y, x});
    maps[y][x] = '.';
    while(!q.empty()){
        int sy = q.front().first;
        int sx = q.front().second;
        q.pop();
        // loop 탈출 조건.
        if((sy==0 || sx==0 || sy==r-1 || sx==c-1) && maps[sy][sx] == '.') return visited[sy][sx]+1;
        // 그 다음 (벽, 불) 피하면서 확인하기. 각각 조건 상이하게.
        for(int i=0; i<4; i++){
            int ny = sy + dy[i];
            int nx = sx + dx[i];
            if(nx<0 || ny<0 || nx>=c || ny>=r) continue;
            if(maps[ny][nx] == '#' || visited[ny][nx] != 0) continue;
            if(visited[sy][sx] + 1 < fire_time[ny][nx]){
                visited[ny][nx] = visited[sy][sx] + 1;
                q.push({ny, nx});
            }
        }
    }
    return 0;
}

int main(){
    FAST_IO;
    cin >> r >> c;
    int start_y, start_x;
    queue<pair<int, int>> fq;
    fill(&fire_time[0][0], &fire_time[0][0]+1000*1000, 987654321);
    // 지도 초기 등록
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> maps[i][j];
            if(maps[i][j] == 'J'){
                start_y = i;
                start_x = j;
            }
            else if(maps[i][j] == 'F'){
                fq.push({i, j});
                fire_time[i][j] = 0;
            }
        }
    }
    // 가장 빠른 탈출 시간이니까 bfs 기반
    // 불 먼저 bfs
    while(!fq.empty()){
        int sy = fq.front().first;
        int sx = fq.front().second;
        fq.pop();
        for(int i=0; i<4; i++){
            int ny = sy + dy[i];
            int nx = sx + dx[i];
            if(nx<0 || ny<0 || nx>=c || ny>=r) continue;
            if(maps[ny][nx] == '#') continue;
            if(fire_time[ny][nx] > fire_time[sy][sx] + 1){
                fire_time[ny][nx] = fire_time[sy][sx] + 1;
                fq.push({ny, nx});
            }
        }
    }

    int result = bfs(start_y, start_x);
    if(!result) cout << "IMPOSSIBLE" << '\n';
    else cout << result << '\n';

    return 0;
}