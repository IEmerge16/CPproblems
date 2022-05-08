#include <bits/stdc++.h>
using namespace std;

// Finds where a target value (in this case, for L and R) should be in the array
// Uses an iterative binary search algorithm
int find_index(long long arr[], int n, long long x) {
    // Left and right pointers (bounds)
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // If the target value is in the array, return the mid index
        if (arr[mid] == x) {
            return mid;
        }
        // If the target value is greater than the middle element, disregard the left half
        else if (arr[mid] < x) {
            left = mid + 1;
        }
        // If the target value is less than the middle element, disregard the right half
        else {
            right = mid - 1;
        }
    }
    // Otherwise, return the right pointer plus 1
    return right + 1;
}

int main() {
    int T;
    cin >> T;
    // Initiate a, b, c, d, the exponents of 2, 3, 5, 7 in the prime factorization of n
    int in = 0, a, b, c, d;
    long long arr[66061];
    // For loop of the possible values of a + b + c + d (0 <= a + b + c + d <= 59)
    for (int r = 0; r < 60; r++) {
        // Three for loops that perform the balls and urns algorithm
        // Visual representation when a + b + c + d = 4: |||****, ||*|***, ..., ||****|, |*||***, ..., *|||***, ..., ****|||
        for (int i = 0; i < r + 1; i++) { // The first '|'
            for (int j = 0; j < r - i + 1; j++) { // The second '|'
                for (int k = 0; k < r - i - j + 1; k++) { // The third '|'
                    long long n;
                    a = i;
                    b = j;
                    c = k;
                    d = r - i - j - k;
                    // Plug a, b, c, d 
                    n = (pow(2, a)) * (pow(3, b)) * (pow(5, c)) * (pow(7, d));
                    // Check whether the nice number n does not exceed 10^18
                    // Must check n > 0 since it might exceed the maximum value of a long long data type
                    if (n <= pow(10, 18) && n > 0) {
                        // If it is within the range, add n to the array
                        arr[in] = n;
                        in++;
                    }
                }
            }
        }
    }
    // Sort the array to perform binary search and find where L and R is
    sort(arr, arr + 66061);
    while (T--) {
        long long L, R;
        cin >> L >> R;
        // Represent the index where L and R, respectively, can be found in the array
        int x, y;
        x = find_index(arr, 66061, L);
        y = find_index(arr, 66061, R);
        // Print y - x + 1, the number of nice numbers between L and R
        cout << y - x + 1 << endl;
    }
}