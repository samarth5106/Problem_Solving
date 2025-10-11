#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n), sorted(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            sorted[i] = A[i];
        }

        sort(sorted.begin(), sorted.end());

        if (k == 1 && A != sorted) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
