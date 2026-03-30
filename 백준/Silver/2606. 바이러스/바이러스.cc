#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int visited[105];
int result;

void dfs(int n, const vector<int> adj[]){
    visited[n] = 1;
    result++;
    for(int v : adj[n]){
        if(!visited[v]) dfs(v, adj);
    }
}

int main(){
    FAST_IO;
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, adj);

    cout << result-1 << '\n';
    
    return 0;
}