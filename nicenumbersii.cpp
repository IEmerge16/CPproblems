#include <bits/stdc++.h>
using namespace std;

const long long N = 1e18;

int lower_bound(vector<long long> a, long long x) {
    int d = 0, r = a.size();
    while (d < r) {
        int m = d + (r - d) / 2;
        if (x <= a[m]) {
            r = m;
        } else {
            d = m + 1;
        }
    }
    return d;
}

int upper_bound(vector<long long> a, long long x) {
    int d = 0, r = a.size();
    while (d < r) {
        int m = d + (r - d) / 2;
        if (x >= a[m]) {
            d = m + 1;
        } else {
            r = m;
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<long long> a; // precalc nice numbers
    long long p2 = 1;
    while (p2 <= N) {
        long long p3 = 1;
        while (p2 * p3 <= N) {
            long long p5 = 1;
            while (p2 * p3 * p5 <= N) {
                long long p7 = 1;
                while (p2 * p3 * p5 * p7 <= N) {
                    a.push_back(p2 * p3 * p5 * p7);
                    p7 *= 7;
                }
                p5 *= 5;
            }
            p3 *= 3;
        }
        p2 *= 2;
    }
    sort(a.begin(), a.end()); // sort to do binary search
    int tt;
    cin >> tt;
    while (tt--) {
        long long d, r;
        cin >> d >> r;
        int lb = lower_bound(a, d);
        int rb = upper_bound(a, r);
        cout << rb - lb << '\n';
    }
    return 0;
}