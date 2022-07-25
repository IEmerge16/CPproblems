#include <bits/stdc++.h>
using namespace std;

string repeat(int k, char c) {
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
            ans += repeat(i - 1, '.');
            ans += '\\';
            ans += repeat(2 * (n - i) + 1, ' ');
            ans += '/';
            ans += repeat(i - 1, '.');
        } else if (i == n) {
            ans += repeat(n - 1, '.');
            ans += '\\';
            ans += 'G';
            ans += '/';
            ans += repeat(n - 1, '.');
        } else {
            ans += repeat(2 * n - i, '.');
            ans += '/';
            ans += repeat(i - n - 1, ' ');
            ans += '|';
            ans += repeat(i - n - 1, ' ');
            ans += '\\';
            ans += repeat(2 * n - i, '.');
        }
        ans += ')';
        cout << ans << '\n';
    }
    return 0;
}