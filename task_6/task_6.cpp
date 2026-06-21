#include <iostream>

int main() {
    int n;
    std::cin >> n;

    while (n--) {
        long long a, b, x, y;
        std::cin >> a >> b >> x >> y;

        long long used = std::min(a, y);
        a -= used;

        long long result = used;
        result += std::min(x, a + b);

        std::cout << result << " ";
    }

    return 0;
}