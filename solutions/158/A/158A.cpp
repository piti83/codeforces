#include <cstdint>
#include <iostream>

// https://codeforces.com/problemset/problem/158/A

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    uint_fast8_t n, k;
    std::cin >> n >> k;

    uint_fast8_t scores[50]{};
    for (uint_fast8_t i{}; i < n; ++i) { std::cin >> scores[i]; }
    return 0;
}
