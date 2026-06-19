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
        --p[i];
    }

    std::string s;
    std::cin >> s;

    std::string result(n, ' ');
    std::vector<bool> used(n, false);

    for (int i = 0; i < n; i++) {
        if (used[i])
            continue;

        std::vector<int> cycle;
        int v = i;

        while (!used[v]) {
            used[v] = true;
            cycle.push_back(v);
            v = p[v];
        }

        int len = cycle.size();
        long long shift = k % len;

        for (int i = 0; i < len; i++) {
            result[cycle[i]] =
                s[cycle[(i + shift) % len]];
        }
    }

    std::cout << result << std::endl;

    return 0;
}