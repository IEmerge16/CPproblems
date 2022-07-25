#include <bits/stdc++.h>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    map<char, bool> mp;
    for (char c : s) {
        mp[c] = true;
    }
    string ans = "";
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) {
            ans += 'G';
        } else if (mp[t[i]]) {
            ans += 'Y';
        } else {
            ans += '.';
        }
    }
    cout << ans << '\n';
    return 0;
}