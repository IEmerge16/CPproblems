#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = 0, ans = 0;
    for (int i = 1; i < n; i++) {
        sum += a[i - 1];
        ans += a[i] * sum;
    }
    cout << ans;
}