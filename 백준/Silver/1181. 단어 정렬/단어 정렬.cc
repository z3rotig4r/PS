#include <bits/stdc++.h>
using namespace std;

int cmp(const string& a, const string& b) {
    if (a.length() == b.length()) {
        return a < b;
    }
    else {
        return a.length() < b.length();
    }
}

int main() {
    int n;
    vector<string> word;
    string temp;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> temp;
        word.push_back(temp);
    }
    sort(word.begin(), word.end(), cmp);

    temp = "";

    for (const string str : word) {
        if (temp == str) continue;
        cout << str << "\n";
        temp = str;
    }
    return 0;
}