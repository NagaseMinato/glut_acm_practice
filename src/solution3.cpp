#include <iostream>
#include <queue>

int main() {
    int k;
    std::cin >> k;
    std::queue<int> unhandle;
    int handle=1;

    while (k / 10 != 0) {
        k /= 10;
    }
    unhandle.push(k);
    while (!unhandle.empty()) {
        int x = unhandle.front();
        unhandle.pop();
        for (int i = x / 2; i > 0; i--) {
            handle++;
            unhandle.push(i);
        }
    }
    std::cout << handle;
    return 0;
}
