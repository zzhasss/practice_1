#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int h;
    std::cin >> h;

    std::vector<std::vector<int>> arr(h);
    for (int i = 0; i < h; ++i) {
        arr[i].resize(i + 1);
        for (int j = 0; j <= i; ++j) {
            std::cin >> arr[i][j];
        }
    }

    std::vector<std::vector<int>> dp(h);

    for (int i = 0; i < h; ++i) {
        dp[i].resize(i + 1);
    }

    // Последний уровень
    for (int j = 0; j < h; ++j) {
        dp[h - 1][j] = arr[h - 1][j];
    }

    // Заполнение снизу вверх
    for (int i = h - 2; i >= 0; --i) {

        for (int j = 0; j <= i; ++j) {

            int left = dp[i + 1][j];
            int right = dp[i + 1][j + 1];

            if (left <= right) {
                dp[i][j] = arr[i][j] + left;

            } else {
                dp[i][j] = arr[i][j] + right;
            }
        }
    }

    // Сумма
    int min_sum = dp[0][0];
    std::cout << min_sum << std::endl;

    return 0;
}