#include <bits/stdc++.h>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s, t, ans;
    cin >> s;
    cin >> t;
    map<char, int> mp;
    for (int i = 0; i < n; i++) {
        mp[s[i]] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) {
            ans += 'G';
        }
        else if (mp[t[i]] == 1) {
            ans += 'Y';
        }
        else {
            ans += '.';
        }
    }
    cout << ans;
}