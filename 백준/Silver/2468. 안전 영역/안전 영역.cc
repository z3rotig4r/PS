#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n, cnt=1;
int arr[100][100];
int visited[100][100];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int sy, int sx, int h){
    visited[sy][sx] = 1;
    for(int i=0; i<4; i++){
        int ny = sy + dy[i];
        int nx = sx + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(!visited[ny][nx] && arr[ny][nx] > h) dfs(ny, nx, h);
    }
    return;
}

int main(){
    int max_h = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            max_h = max(max_h, arr[i][j]);
        }
    }
    for(int h=1; h<max_h; h++){
        memset(visited, 0, sizeof(visited));
        int current_cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j] > h && !visited[i][j]){
                    dfs(i, j, h);
                    current_cnt++;
                }
            }
        }
        cnt = max(cnt, current_cnt);
    }
    cout << cnt << '\n';

    return 0;
}