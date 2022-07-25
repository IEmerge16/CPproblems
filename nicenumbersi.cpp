#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long n;
        cin >> n;
        while (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0) {
            if (n % 2 == 0) {
                n /= 2;
            }
            if (n % 3 == 0) {
                n /= 3;
            }
            if (n % 5 == 0) {
                n /= 5;
            }
            if (n % 7 == 0) {
                n /= 7;
            }
        }
        cout << (n == 1 ? "nice" : "not nice") << '\n';
    }
    return 0;
}