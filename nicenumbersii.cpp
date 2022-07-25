#include <bits/stdc++.h>
using namespace std;

const long long max_N = 1e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    set<long long> st; // precalc nice numbers
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
    set<pair<long long, int>> st2; // index set of nice numbers
    int i = 1;
    for (long long N : st) {
        st2.insert({N, i});
        i++;
    }
    int tt;
    cin >> tt;
    while (tt--) {
        long long l, r;
        cin >> l >> r;
        auto lb = st2.lower_bound({l, 0});
        auto rb = st2.upper_bound({r, st.size()});
        auto lp = *lb, rp = *rb;
        int li = lp.second, ri = rp.second;
        if (rb == st2.end()) {
            ri = st.size() + 1;
        }
        cout << ri - li << '\n';
    }
    return 0;
}