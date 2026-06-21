#include <iostream>

int main() {
    int n;
    std::cin >> n;

    while (n--) {
        long long a, b, x, y;
        std::cin >> a >> b >> x >> y;

        long long ans = std::min(a + b, x + y);

        if (b > x)
            ans -= std::min(y, b - x);

        std::cout << ans << " ";
    }

    return 0;
}