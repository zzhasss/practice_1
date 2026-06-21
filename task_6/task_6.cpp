#include <iostream>

int main() {
    int n;
    std::cin >> n;

    while (n--) {
        long long a, b, x, y;
        std::cin >> a >> b >> x >> y;

        long long used = std::min(a, y);

        long long result = used;
        result += std::min(x, b);

        std::cout << result << " ";
    }

    return 0;
}