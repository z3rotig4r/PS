#include<vector>
#include<queue>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void bfs(int y, int x, const vector<vector<int>> &maps, vector<vector<int>>& visited){
    int n = maps.size();
    int m = maps[0].size();
    queue<pair<int,int>> q;
    visited[y][x] = 1;
    q.push({y, x});
    while(!q.empty()){
        int sy = q.front().first;
        int sx = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int ny = sy + dy[i];
            int nx = sx + dx[i];
            if(ny<0 || nx<0 || ny>=n || nx>= m) continue;
            if(maps[ny][nx] == 0 || visited[ny][nx] != -1) continue;
            visited[ny][nx] = visited[sy][sx] + 1;
            q.push({ny, nx});
        }
    }
    return;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> visited(n, vector<int>(m, -1));
    bfs(0, 0, maps, visited);
    answer = visited[n-1][m-1];
    return answer;
}