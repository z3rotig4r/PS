#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main(){
    FAST_IO;
    int m, n, result=0;
    int arr[1000][1000];
    int visited[1000][1000];
    memset(visited, 0, sizeof(visited));
    // input processing
    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    // bfs
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 1 && !visited[i][j]){
                q.push({i, j});
            }
        }
    }
    while(!q.empty()){
        int sy = q.front().first;
        int sx = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int ny = sy + dy[i];
            int nx = sx + dx[i];
            if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
            if(arr[ny][nx] == -1 || arr[ny][nx] == 1 || visited[ny][nx]) continue;
            visited[ny][nx] = visited[sy][sx] + 1;
            arr[ny][nx] = 1;
            if(visited[ny][nx] > result) result = visited[ny][nx];
            q.push({ny, nx});
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 0){
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << result << '\n';

    return 0;
}