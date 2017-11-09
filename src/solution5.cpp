
#include <iostream>

int matrix[1024][1024] = { 0 };

int main() {
    int n;
    std::cin >> n;
    matrix[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int k = 1; k <= i; k++) {
            if (k == 1) {
                matrix[i][1] = matrix[i - 1][i - 1]+1;
            }
            else {
                matrix[i][k] = matrix[i][k - 1] + 1;
            }
        }
    }
    int * cursor = new int[n + 1];
    for (int t = 1; t <= n; t++) {
        cursor[t] = t;
    }

    for (int m = 1; m <= n; m++) {
        for (int p = m; p <= n; p++) {
            if (cursor[p] != 0) {
                std::cout << matrix[p][cursor[p]] << " ";
                cursor[p]--;
            }
            
        }
        std::cout << "\n";
    }
    return 0;;
}
