#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int x = 0;

    for (int i = 0; i < n; ++i) {
        std::string op;
        std::cin >> op;
        int j = 0;
        while (op.at(j) != '-' && op.at(j) != '+') { j++; }
        if (op.at(j) == '+') {
            x++;
        } else {
            x--;
        }
    }

    std::cout << x << std::endl;
}
