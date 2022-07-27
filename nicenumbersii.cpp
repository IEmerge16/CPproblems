#include <bits/stdc++.h>
using namespace std;

const long long max_n = 1e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<long long> nice_nums;
    long long p2 = 1;
    while (p2 <= max_n) {
        long long p3 = 1;
        while (p2 * p3 <= max_n) {
            long long p5 = 1;
            while (p2 * p3 * p5 <= max_n) {
                long long p7 = 1;
                while (p2 * p3 * p5 * p7 <= max_n) {
                    nice_nums.push_back(p2 * p3 * p5 * p7);
                    p7 *= 7;
                }
                p5 *= 5;
            }
            p3 *= 3;
        }
        p2 *= 2;
    }
    sort(nice_nums.begin(), nice_nums.end());
    int tt;
    cin >> tt;
    while (tt--) {
        long long l, r;
        cin >> l >> r;
        auto it_l = lower_bound(nice_nums.begin(), nice_nums.end(), l);
        auto it_r = upper_bound(nice_nums.begin(), nice_nums.end(), r);
        cout << (int) (it_r - it_l) << '\n';
    }
    return 0;
}