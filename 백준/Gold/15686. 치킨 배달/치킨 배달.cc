#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void combination(int start, vector<int>& v, vector<vector<int>>& chickenList, const vector<pair<int, int>>& house, const vector<pair<int, int>>& chicken, const int& m){
    if(v.size() == m){
        chickenList.push_back(v);
        return;
    }
    for(int i=start; i<chicken.size(); i++){
        v.push_back(i);
        combination(i+1, v, chickenList, house, chicken, m);
        v.pop_back();
    }
    return;
}


int main(){
    int n, m;
    int result=987654321;
    cin >> n >> m;
    int arr[54][54];
    vector<vector<int>> chickenList;
    vector<pair<int, int>> house, chicken;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1) house.push_back({i, j});
            else if(arr[i][j] == 2) chicken.push_back({i, j});
        }
    }
    vector<int> v;
    combination(0, v, chickenList, house, chicken, m);
    for(const vector<int>& cList : chickenList){
        int ret = 0;
        for(const pair<int, int>& h : house){
            int mini = 987654321;
            for(int ch : cList){
                int distance = abs(h.first - chicken[ch].first) + abs(h.second - chicken[ch].second);
                mini = min(mini, distance);
            }
            ret += mini;
        }
        result = min(result, ret);
    }
    cout << result << '\n';

    return 0;
}