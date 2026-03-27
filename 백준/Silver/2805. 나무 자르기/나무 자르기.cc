#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    FAST_IO;
    int n, m, h;
    vector<int> v; // 나무 길이 vector
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    // binary search로 O(logn) 탐색할 것임.
    sort(v.begin(), v.end());
    int start = 0;
    int end = v.back();
    int ans = 0; // 답변 저장용
    while(start <= end){
        int mid = (start+end)/2;
        long long sum = 0; // 자료형 크기 조심
        for(int x : v){
            if(x > mid) sum += (x-mid);
        }
        if(sum >= m){
            ans = mid;
            start = mid + 1;
        }
        else end = mid -1;
    }
    cout << ans << '\n';


    return 0;
}