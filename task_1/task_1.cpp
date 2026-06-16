#include <iostream>
#include <vector>

const int INF = 10000000;

int main() {
    int h = 0;
    std::cin >> h;
    int n = h *(h + 1) / 2;

    int* arr = new int[n]; 
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int count = 0;
    int i = 0;


    std::vector<int> result_arr;
    int result = 0;

    while (i < n) {

        int min_n = INF;
        count++;

        for(int j = 0; j < count; j++) {

            if (min_n > arr[i]) {
                min_n = arr[i];
            }

            i++;

            if (j + 1 == count) {
                result += min_n;
                result_arr.push_back(min_n);
            }
        }
    }

    std::cout << result;
    for (int i = 0; i < result_arr.size(); i++) {
        std::cout << result_arr[i];
    }
    return 0;
}