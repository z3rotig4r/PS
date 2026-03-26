#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int main(){
    FAST_IO;
    int n;
    int max=0;
    double sum=0;
    vector<int> v;
    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        if(max < tmp) max = tmp;
        v.push_back(tmp);
    }
    for(int x : v){
        sum += (double)x/max*100;
    }
    cout << sum/n << '\n';


    return 0;
}