#include <bits/stdc++.h>
using namespace std;

const long long max_N = 1e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // precalculate nice numbers
    set<long long> st;
    long long p2 = 1;
    for (int i = 0; i <= 59 && p2 <= max_N; i++, p2 *= 2) {
        long long p3 = 1;
        for (int j = 0; j <= 37 && p2 * p3 <= max_N; j++, p3 *= 3) {
            long long p5 = 1;
            for (int k = 0; k <= 25 && p2 * p3 * p5 <= max_N; k++, p5 *= 5) {
                long long p7 = 1;
                for (int l = 0; l <= 21 && p2 * p3 * p5 * p7 <= max_N; l++, p7 *= 7) {
                    st.insert(p2 * p3 * p5 * p7);
                }
            }
        }
    }

    // index nice numbers
    int i = 1;
    set<pair<long long, int>> st2;
    for (long long N : st) {
        st2.insert({N, i});
        i++;
    }

    int tt;
    cin >> tt;
    while (tt--) {
        long long l, r;
        cin >> l >> r;
        auto lb = *st2.lower_bound({l, 0});
        auto rb = *st2.upper_bound({r, st.size()});
        int lc = lb.first, li = lb.second;
        int rc = rb.first, ri = rb.second;
        cout << ri - li << '\n';
    }

    return 0;
}