#include <bits/stdc++.h>
using namespace std;

const long long max_n = 1e18;

int lower_bound(vector<long long> arr, long long x) {
    int low = 0, high = arr.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (x <= arr[mid]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int upper_bound(vector<long long> arr, long long x) {
    int low = 0, high = arr.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (x >= arr[mid]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

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
        int lb = lower_bound(nice_nums, l);
        int rb = upper_bound(nice_nums, r);
        cout << rb - lb << '\n';
    }
    return 0;
}