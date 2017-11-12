
#include <iostream>
#include <cstring>
#include <queue>

int closed[100000 + 1];

int bfs(int n, int k) {
    int res = 0;
    memset(closed, 0, sizeof(closed));
    std::queue<std::pair<int, int>> q;	//position,step
    q.push(std::make_pair(n, 0));
    while (!q.empty()) {
        std::pair<int, int> x = q.front();
        q.pop();
        
        if (x.first == k) {
            res = x.second;
            break;
        }
        if ((x.first + 1 <= 100000) && closed[x.first + 1] == false) {
            closed[x.first+1] = true;
            q.push(std::make_pair(x.first + 1, x.second + 1));
        }
        if ((x.first -1 >= 0) && closed[x.first - 1] == false) {
            closed[x.first-1] = true;
            q.push(std::make_pair(x.first - 1, x.second + 1));
        }
        if ((x.first * 2 <= 100000) && closed[x.first * 2] == false) {
            closed[x.first*2] = true;
            q.push(std::make_pair(x.first * 2, x.second + 1));
        }
    }
    return res;
}

int main() {
    int n;
    int k;
    std::cin >> n >> k;
    std::cout << bfs(n, k)<<"\n";
    return 0;
}

