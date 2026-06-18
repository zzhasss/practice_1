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

    // Префиксная ссумма
    long long Sum(int idx) {
        long long res = 0;

        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }

        return res;
    }

    //Сумма на диапазоне 
    long long RangeSum(int l, int r) {
        return Sum(r) - Sum(l);
    }
};