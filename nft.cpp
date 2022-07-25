#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<long long, bool> sub;
    map<long long, long long> bot;
    map<long long, long long> top;
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
            bot[cur] = cur;
            top[cur] = cur;
            if (sub[cur - 1] && sub[cur + 1]) {
                bot[cur] = bot[cur - 1];
                top[cur] = top[cur + 1];
                top[cur - 1] = top[cur];
                bot[cur + 1] = bot[cur];
            } else if (sub[cur - 1]) {
                bot[cur] = bot[cur - 1];
                top[cur - 1] = top[cur];
            } else if (sub[cur + 1]) {
                top[cur] = top[cur + 1];
                bot[cur + 1] = bot[cur];
            }
            if (sub[pos]) {
                cout << top[pos] - pos + 1 << '\n';
                pos = top[pos] + 1;
            } else {
                cout << 0 << '\n';
            }
        }
    }
    return 0;
}