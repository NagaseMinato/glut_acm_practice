#include <iostream>
#include <string>

char field[1024][1024];
int n, m;

void dfs(int x, int y) {
    int pos[8][2] = { {0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1} };
    for (int i = 0; i < 8; i++) {
        int nx = x + pos[i][0];
        int ny = y + pos[i][1];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
        	continue;
        }
        if (field[nx][ny] == 'W') {
            field[nx][ny] = '.';
            dfs(nx,ny); 
        }
    }
}

int main() {
    int result = 0;
    std::cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int k = 0; k < m; k++){
            char c;
            std::cin >> c;
            field[i][k] = c;
        }

    }

    for (int p = 0; p < n; p++) {
        for (int q = 0; q < m; q++) {
            if (field[p][q] == 'W') {
                dfs(p,q);
                result++;
            }
        }
    }
    std::cout << result;
    return 0;
}
