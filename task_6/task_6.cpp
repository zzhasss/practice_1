#include <iostream>

int main() {
    int n;
    std::cin >> n;

    while (n--) {
        long long a, b, x, y;
        std::cin >> a >> b >> x >> y;

        std::cout << std::min(a + b, x + y) << " ";
    }

    return 0;
}