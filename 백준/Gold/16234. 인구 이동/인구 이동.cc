#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int a[50][50];
int visited[50][50];
int n, l, r;

bool bfs(int y, int x){
    queue<pair<int, int>> q;
    vector<pair<int, int>> v_idx;
    int sum=0;
    q.push({y, x});
    v_idx.push_back({y, x});
    visited[y][x] = 1;
    while(!q.empty()){
        int sy = q.front().first;
        int sx = q.front().second;
        sum += a[sy][sx];
        q.pop();
        for(int i=0; i<4; i++){
            int ny = sy + dy[i];
            int nx = sx + dx[i];
            if(ny<0 || nx<0 || ny>=n || nx>=n) continue;
            if(abs(a[ny][nx]-a[sy][sx]) >= l && abs(a[ny][nx]-a[sy][sx]) <= r && !visited[ny][nx]){
                visited[ny][nx] = 1;
                q.push({ny, nx});
                v_idx.push_back({ny, nx});
            }
        }
    }
    int ret = sum / v_idx.size();
    if(v_idx.size() != 1){
        for(pair<int, int> p : v_idx){
            a[p.first][p.second] = ret;
        }
        return true;
    }
    return false;
}

int main(){
    FAST_IO;
    int days=0;
    bool flag=true;
    cin >> n >> l >> r;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    while(true){
        bool flag=false;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){
                    if(bfs(i, j)) flag=true;
                }
            }
        }
        memset(visited, 0, sizeof(visited));
        if(!flag) break;
        else days++;
    }
    
    cout << days << '\n';
    return 0;
}