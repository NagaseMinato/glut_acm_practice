#include <iostream>

int main() {
    float f;
    std::cin >> f;
    while (f != 0.00) {
        float sum = 0.0;
        int i;
        for (i = 2; sum < f; i++) {
            sum += (1.0 / i);
        }
        std::cout << i-2 << " card(s)\n";
        std::cin >> f;
    }
    return 0;
}
