// https://codeforces.com/contest/282/problem/A
// https://codeforces.com/contest/282/submission/399219751

#include <iostream>

int main() {
    int         n, x{};
    std::string operation;
    std::cin >> n;
    while (n--) {
        std::cin >> operation;
        if (operation[1] == '+') {
            x++;
        } else {
            x--;
        }
    }
    std::cout << x;
}
