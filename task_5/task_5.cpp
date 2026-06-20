#include <iostream>
#include <vector>

int main() {
    int h, w;
    std::cin >> h >> w;

    int minRow = h;
    int minCol = w;
    int maxRow = -1;
    int maxCol = -1;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int x;
            std::cin >> x;

            if (x == 1) {
                if (i < minRow)
                    minRow = i;

                if (j < minCol)
                    minCol = j;

                if (i > maxRow)
                    maxRow = i;

                if (j > maxCol)
                    maxCol = j;
            }
        }
    }

    std::cout << minRow - 1 << " "
              << minCol - 1 << " "
              << maxRow + 1 << " "
              << maxCol + 1;

    return 0;
}