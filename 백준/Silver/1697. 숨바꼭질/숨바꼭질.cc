#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int max_int = 100001;

int visited[max_int];
int n, k;

void bfs(int sx, int goal){
    queue<int> q;
    visited[sx] = 1;
    q.push(sx);
    while(!q.empty()){
        int cx = q.front(); q.pop();
        if(cx == goal){
            cout << visited[cx] - 1 << '\n';
            return;
        };
        int next_nodes[3] = {cx-1, cx+1, cx*2};
        for(int i : next_nodes){
            int nx = i;
            if(nx<0 || nx>=max_int || visited[nx]) continue;
            visited[nx] = visited[cx]+1;
            q.push(nx);
        }

    }
    
    return ;
}

int main(){
    FAST_IO;
    cin >> n >> k;
    bfs(n, k);

    return 0;
}