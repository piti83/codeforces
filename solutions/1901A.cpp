// https://codeforces.com/contest/1901/problem/A
// https://codeforces.com/contest/1901/submission/399253929

#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, x;
        std::cin >> n >> x;

        int prev, current;
        std::cin >> prev;
        int min_capacity = prev;
        for (int i{1}; i < n; ++i) {
            std::cin >> current;
            min_capacity = (current - prev > min_capacity) ? current - prev : min_capacity;
            prev         = current;
        }
        if ((x - prev) * 2 > min_capacity) {
            min_capacity = (x - prev) * 2;
        }

        std::cout << min_capacity << std::endl;
    }
}
