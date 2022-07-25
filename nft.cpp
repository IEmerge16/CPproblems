#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<long long, bool> sub;
    map<long long, long long> below;
    map<long long, long long> above;
    long long pos = 0, tot = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "UP") {
            int x;
            cin >> x;
            cout << pos + tot << '\n';
            tot += x;
            pos = -tot;
        } else {
            int y;
            cin >> y;
            long long cur = y - tot;
            sub[cur] = true;
            below[cur] = cur;
            above[cur] = cur;
            if (sub[cur - 1] && sub[cur + 1]) {
                below[cur] = below[cur - 1];
                above[cur] = above[cur + 1];
                above[cur - 1] = above[cur];
                below[cur + 1] = below[cur];
            } else if (sub[cur - 1]) {
                below[cur] = below[cur - 1];
                above[cur - 1] = above[cur];
            } else if (sub[cur + 1]) {
                above[cur] = above[cur + 1];
                below[cur + 1] = below[cur];
            }
            if (sub[pos]) {
                cout << above[pos] - pos + 1 << '\n';
                pos = above[pos] + 1;
            } else {
                cout << 0 << '\n';
            }
        }
    }
    return 0;
}