#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    FAST_IO;
    int n, m;
    int card[100];
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> card[i];
    }
    vector<int> com;
    for(int i=0; i<n-3; i++) com.push_back(0);
    for(int i=0; i<3; i++) com.push_back(1);

    int result = 0;
	do {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (com[i]==1) {
				sum += card[i];
				if (sum > m)break;
			}
		}

		if (sum <= m && sum > result) {
			result = sum;
		}

	} while (next_permutation(com.begin(), com.end()));

	cout << result;

    return 0;
}