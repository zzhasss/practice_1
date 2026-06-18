#include <iostream>
#include <vector>

class T {
private:
    std::vector<long long> bit;
    int n;

public:
    T(int n) : n(n) {
        bit.assign(n + 1, 0);
    }

    // Добавить значение
    void Add(int idx, long long val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    // Префиксная сумма
    long long Sum(int idx) {
        long long res = 0;

        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }

        return res;
    }

    // Сумма на диапазоне 
    long long RangeSum(int l, int r) {
        return Sum(r) - Sum(l - 1);
    }
};

int main() {
    int n, k;
    std::cin >> n >> k;

    T tree(n);

    for (int q = 0; q < k; q++) {
        int type;
        std::cin >> type;

        if (type == 1) {
            int i;
            long long x;
            std::cin >> i >> x;

            tree.Add(i, x);

        } else {
            int l, r;
            std::cin >> l >> r;

            std::cout << tree.RangeSum(l, r) << '\n';
        }
    }

    return 0;
}