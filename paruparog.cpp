#include <bits/stdc++.h>
using namespace std;

string repeat(string s, int k, char c) {
    for (int i = 0; i < k; i++) {
        s += c;
    }
    return s;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < 2 * n + 1; i++) {
        string l;
        l += '(';
        if (i < n) {
            l = repeat(l, i - 1, '.');
            l += '\\';
            l = repeat(l, 2 * (n - i) + 1, ' ');
            l += '/';
            l = repeat(l, i - 1, '.');
        }
        else if (i == n) {
            l = repeat(l, i - 1, '.');
            l += '\\';
            l += 'G';
            l += '/';
            l = repeat(l, i - 1, '.');
        }
        else {
            l = repeat(l, 2 * n - i, '.');
            l += '/';
            l = repeat(l, i - n - 1, ' ');
            l += '|';
            l = repeat(l, i - n - 1, ' ');
            l += '\\';
            l = repeat(l, 2 * n - i, '.');
        }
        l += ')';
        cout << l << '\n';
    } 
}