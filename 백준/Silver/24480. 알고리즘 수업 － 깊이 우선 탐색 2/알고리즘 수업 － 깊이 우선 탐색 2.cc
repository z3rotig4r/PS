#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int cnt = 1;

int ord[100005]; //방문 순서 고려, visited 대신 사용
vector<int> adj[100001];

void dfs(int u){
    ord[u] = cnt++;
    for(int v : adj[u]){
        if(!ord[v]) dfs(v);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int u, v;

    cin >> n >> m >> r;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); //무방향 그래프
    }
    for(int i=1; i<=n; i++) sort(adj[i].rbegin(), adj[i].rend()); //내림차순 방문
    dfs(r);
    for(int i=1; i<=n; i++) {
        if(!ord[i]) cout << 0 << '\n';
        else cout << ord[i] << '\n';
    }
    return 0;
}