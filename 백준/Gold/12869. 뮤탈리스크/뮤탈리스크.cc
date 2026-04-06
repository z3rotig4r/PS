#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int a[3], n, visited[64][64][64];

int arr[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 1, 9},
    {3, 9, 1},
    {1, 9, 3},
    {1, 3, 9}
};

typedef struct{
    int a, b, c;
}S;

queue<S> q;

int bfs(int a, int b, int c){
    visited[a][b][c] = 1;
    q.push({a, b, c});
    while(q.size()){
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if(visited[0][0][0]) break;
        for(int i=0; i<6; i++){
            // 음수 방지.
            int na = max(0, a-arr[i][0]);
            int nb = max(0, b-arr[i][1]);
            int nc = max(0, c-arr[i][2]);
            if(visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }
    return visited[0][0][0]-1;
}

int main(){
    FAST_IO;
    // 이때, 탐색은 bfs 기반으로.

    // **INPUT**
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << bfs(a[0], a[1], a[2]) << '\n';


    return 0;
}