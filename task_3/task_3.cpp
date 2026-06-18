#include <iostream>
#include <vector>


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<long long> snow(n + 1, 0);

    for (int q = 0; q < k; q++) {
        int type;
        std::cin >> type;

        if (type == 1) {
            int i;
            long long x;
            std::cin >> i >> x;

            snow[i] = x;
        } else {
            int l, r;
            std::cin >> l >> r;

            long long sum = 0;
            for (int i = l; i <= r; i++) {
                sum += snow[i];
            }

            std::cout << sum << '\n';
        }
    }

    return 0;
}