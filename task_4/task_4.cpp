#include <iostream>
#include <vector>
#include <string>


int main() {
    int n;
    long long k;
    std::cin >> n >> k;

    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    std::string s;
    std::cin >> s;

    std::string result(n, ' ');

    for (int i = 0; i < n; i++) {
        result[p[i] - 1] = s[i];
    }

    std::cout << result << std::endl;

    return 0;
}