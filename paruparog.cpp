#include <bits/stdc++.h>
using namespace std;

string rep_char(int k, char c) {
    string s = "";
    for (int i = 0; i < k; i++) {
        s += c;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        string ans = "";
        ans += '(';
        if (i < n) {
            ans += rep_char(i - 1, '.');
            ans += '\\';
            ans += rep_char(2 * (n - i) + 1, ' ');
            ans += '/';
            ans += rep_char(i - 1, '.');
        } else if (i == n) {
            ans += rep_char(n - 1, '.');
            ans += '\\';
            ans += 'G';
            ans += '/';
            ans += rep_char(n - 1, '.');
        } else {
            ans += rep_char(2 * n - i, '.');
            ans += '/';
            ans += rep_char(i - n - 1, ' ');
            ans += '|';
            ans += rep_char(i - n - 1, ' ');
            ans += '\\';
            ans += rep_char(2 * n - i, '.');
        }
        ans += ')';
        cout << ans << '\n';
    }
    return 0;
}