#include <iostream>

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string word;
        std::cin >> word;

        if (word.length() <= 10) {
            std::cout << word << std::endl;
        } else {
            std::cout << word.at(0) << word.length() - 2 << word.at(word.length() - 1) << std::endl;
        }
    }
    return 0;
}
