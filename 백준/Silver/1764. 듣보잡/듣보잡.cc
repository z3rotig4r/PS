#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

//O(N*M) -> O((N+M)logN)

int main(){
    FAST_IO;
    int n, m;
    cin >> n >> m;

    string tmp;
    vector<string> vs, result;
    for(int i=0; i<n; i++){
        cin >> tmp;
        vs.push_back(tmp);
    }
    sort(vs.begin(), vs.end());
    // 입력받으면서 binary search로 겹치는 거 확인
    for(int i=0; i<m; i++){
        cin >> tmp;
        int start = 0, end = n-1;
        while(start <= end){
            int mid = (start+end)/2;
            if(tmp < vs[mid]){
                end = mid-1;
            }
            else if (tmp > vs[mid]){
                start = mid+1;
            }
            else{
                result.push_back(tmp);
                break;
            }
            mid /= 2;
        }
    }
    
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for(const string& x : result) cout << x << "\n";

    return 0;
}