#include <iostream>
#include <string>


int main() {
    std::string s;
    std::cin >> s;

    bool ok = true;

    if (s.size() != 6)
        ok = false;

    if (!(s[0] >= 'A' && s[0] <= 'Z'))
        ok = false;

    for (int i = 1; i <= 3; i++) {
        if (!(s[i] >= '0' && s[i] <= '9'))
            ok = false;
    }

    if (!(s[4] >= 'A' && s[4] <= 'Z'))
        ok = false;

    if (!(s[4] >= 'A' && s[4] <= 'Z'))
        ok = false;

    std::cout << (ok ? "Yes" : "No");

    return 0;
}