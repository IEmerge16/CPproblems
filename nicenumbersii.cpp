#include <bits/stdc++.h>
using namespace std;

const long long max_N = 1e18;

int lower_bound(int n, vector<long long> a, long long x) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (x <= a[mid]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int upper_bound(int n, vector<long long> a, long long x) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (x >= a[mid]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<long long> a; // precalc nice numbers
    long long p2 = 1;
    for (int i = 0; i <= 59 && p2 <= max_N; i++, p2 *= 2) {
        long long p3 = 1;
        for (int j = 0; j <= 37 && p2 * p3 <= max_N; j++, p3 *= 3) {
            long long p5 = 1;
            for (int k = 0; k <= 25 && p2 * p3 * p5 <= max_N; k++, p5 *= 5) {
                long long p7 = 1;
                for (int l = 0; l <= 21 && p2 * p3 * p5 * p7 <= max_N; l++, p7 *= 7) {
                    a.push_back(p2 * p3 * p5 * p7);
                }
            }
        }
    }
    sort(a.begin(), a.end());
    int tt;
    cin >> tt;
    while (tt--) {
        long long l, r;
        cin >> l >> r;
        int lb = lower_bound(a.size(), a, l);
        int rb = upper_bound(a.size(), a, r);
        cout << rb - lb << '\n';
    }
    return 0;
}