#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int arr[100][100];
    int k=1;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            arr[i][j] = k++;
        }
    }
    for(auto query : queries){
        int r1 = query[0]-1;
        int c1 = query[1]-1;
        int r2 = query[2]-1;
        int c2 = query[3]-1;
        int tmp = arr[r1][c1];
        int min_val = tmp;
        // 위로 당김
        for(int i=r1; i<r2; i++){
            arr[i][c1] = arr[i+1][c1];
            min_val = min(min_val, arr[i][c1]);
        }
        for(int i=c1; i<c2; i++){
            arr[r2][i] = arr[r2][i+1];
            min_val = min(min_val, arr[r2][i]);
        }
        for(int i=r2; i>r1; i--){
            arr[i][c2] = arr[i-1][c2];
            min_val = min(min_val, arr[i][c2]);
        }
        for(int i=c2; i>c1; i--){
            arr[r1][i] = arr[r1][i-1];
            min_val = min(min_val, arr[r1][i]);
        }
        arr[r1][c1+1] = tmp;
        answer.push_back(min_val);
    }
    return answer;
}