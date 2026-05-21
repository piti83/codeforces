#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int result = 0;

    for (int i = 0; i < n; ++i) {
        int sub_sum = 0;
        for (int j = 0; j < 3; ++j) {
            int val;
            std::cin >> val;
            sub_sum += val;
        }
        if (sub_sum >= 2) { result++; }
    }
    std::cout << result << std::endl;
}
