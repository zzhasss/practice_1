#include <iostream>
#include <vector>

int main()
{
    int h, w;
    std::cin >> h >> w;

    std::vector<std::vector<int>> a(h, std::vector<int>(w));

    int r1 = -1;
    int c1 = -1;
    int r2 = -1;
    int c2 = -1;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            std::cin >> a[i][j];

            if (a[i][j] == 1)
            {
                if (r1 == -1)
                {
                    r1 = i;
                    c1 = j;
                }

                r2 = i;
                c2 = j;
            }
        }
    }

    std::cout << r1 << " " << c1 << " "
              << r2 << " " << c2;

    return 0;
}