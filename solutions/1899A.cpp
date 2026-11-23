// https://codeforces.com/problemset/problem/1899/A
// https://codeforces.com/problemset/submission/1899/399618167

#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        if ((n + 1) % 3 == 0 || (n - 1) % 3 == 0) {
            std::cout << "First" << std::endl;
            continue;
        } else {
            std::cout << "Second" << std::endl;
        }
    }
}
