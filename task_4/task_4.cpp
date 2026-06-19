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
        p[i]--;
    }

    std::string s;
    std::cin >> s;

    std::vector<int> rev(n);

    for (int i = 0; i < n; i++) {
        rev[p[i]] = i;
    }

    while (k--) {
        std::string temp(n, ' ');

        for (int i = 0; i < n; i++) {
            temp[i] = s[rev[i]];
        }

        s = temp;
    }

    std::cout << s << std::endl;

    return 0;
}