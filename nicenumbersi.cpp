#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long N;
        cin >> N;
        string ans = "not nice";
        while (N % 2 == 0 || N % 3 == 0 || N % 5 == 0 || N % 7 == 0 || N == 1) {
            if (N % 2 == 0) {
                N /= 2;
            }
            if (N % 3 == 0) {
                N /= 3;
            }
            if (N % 5 == 0) {
                N /= 5;
            }
            if (N % 7 == 0) {
                N /= 7;
            }
            if (N == 1) {
                ans = "nice";
                break;
            }
        }
        cout << ans << '\n';
    }
}