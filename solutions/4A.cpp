// https://codeforces.com/contest/4/problem/A
// https://codeforces.com/contest/4/submission/399208055

#include <iostream>

int main() {
    short w;
    std::cin >> w;

    if (!(w % 2) && w >= 4) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}
