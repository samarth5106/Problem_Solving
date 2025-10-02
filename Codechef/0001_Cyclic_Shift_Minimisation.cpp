#include <iostream>
#include <vector>
#include <numeric>

void solve() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int value = n - i;
     cout << value << (i == n - 1 ? "" : " ");
    }
   cout <<endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
