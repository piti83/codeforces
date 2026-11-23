// https://codeforces.com/problemset/problem/1903/A
// https://codeforces.com/problemset/submission/1903/399617383

#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        if (k >= 2) {
            std::cout << "YES" << std::endl;
            int dummy;
            for (int i = 0; i < n; ++i) {
                std::cin >> dummy;
            }
        } else {
            int  previous, current;
            bool flag = false;
            std::cin >> previous;
            for (int i = 1; i < n; ++i) {
                std::cin >> current;
                if (current < previous) {
                    flag = true;
                }
                previous = current;
            }
            if (flag) {
                std::cout << "NO" << std::endl;
            } else {
                std::cout << "YES" << std::endl;
            }
        }
    }
}
