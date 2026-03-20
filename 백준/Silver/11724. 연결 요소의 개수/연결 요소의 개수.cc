#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n, m;
int ret;
vector<int> adj[1004];
int visited[1004];

void dfs(int u){
    visited[u] = 1;
    for(int v : adj[u]){
        if(visited[v] == 0) dfs(v);
    }
    return;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        if(visited[i] == 0){
            ret++;
            dfs(i);
        }
    }

    cout << ret << '\n';
    return 0;
}