#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = 0, cur_sum = 0;
    for (int i = 0; i < n; i++) {
        ans += (long long) cur_sum * a[i];
        cur_sum += a[i];
    }
    cout << ans << '\n';
    return 0;
}