// https://codeforces.com/problemset/problem/1896/A
// https://codeforces.com/problemset/submission/1896/399620434

#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int first;
        std::cin >> first;
        if (first == 1) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
        for (int i = 1; i < n; ++i) {
            std::cin >> first;
        }
    }
}
