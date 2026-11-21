// https://codeforces.com/contest/158/problem/A
// https://codeforces.com/contest/158/submission/399224933

#include <iostream>

int main() {
    int n, k, current_score, participants{};
    std::cin >> n >> k;
    while (k--) {
        std::cin >> current_score;
        if (current_score) {
            participants++;
        }
        n--;
    }
    int next_score;
    std::cin >> next_score;
    while (next_score == current_score && n--) {
        if (next_score) {
            participants++;
        }
        std::cin >> next_score;
    }
    std::cout << participants;
}
