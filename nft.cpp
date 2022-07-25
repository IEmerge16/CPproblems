#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<ll, bool> sub;
    map<ll, ll> bot;
    map<ll, ll> top;
    ll pos = 0, tot = 0;
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
            ll cur = y - tot;
            sub[cur] = true;
            bot[cur] = cur;
            top[cur] = cur;
            if (sub[cur - 1]) {
                bot[cur] = bot[cur - 1];
            }
            if (sub[cur + 1]) {
                top[cur] = top[cur + 1];
            }
            top[bot[cur]] = top[cur];
            bot[top[cur]] = bot[cur];
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