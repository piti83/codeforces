// https://codeforces.com/problemset/problem/1900/A
// https://codeforces.com/contest/1900/submission/399558578

#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int         n;
        std::string row;

        std::cin >> n >> row;

        int  counter = 0;
        bool flag    = false;

        if (row[0] == '.') {
            counter++;
        }

        if (row[n - 1] == '.' && n > 1) {
            counter++;
        }

        for (int i = 1; i < n - 1; ++i) {
            if (row[i] == '.' && row[i - 1] == '.' && row[i + 1] == '.') {
                flag = true;
                break;
            } else if (row[i] == '.') {
                counter++;
            }
        }

        if (flag) {
            std::cout << "2" << std::endl;
        } else {
            std::cout << counter << std::endl;
        }
    }
}
