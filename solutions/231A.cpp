// https://codeforces.com/contest/231/problem/A
// https://codeforces.com/contest/231/submission/399219042

#include <iostream>

int main() {
    int n, c1, c2, c3, number{};
    std::cin >> n;
    while (n--) {
        std::cin >> c1 >> c2 >> c3;
        if (c1 + c2 + c3 >= 2) {
            number += 1;
        }
    }
    std::cout << number;
    return 0;
}
