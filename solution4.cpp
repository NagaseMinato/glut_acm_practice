#include <iostream>
#include <algorithm>
#include <map>

int main() {
    int m;
    std::cin >> m;

    while (m != 0) {
        std::map<int, int> coin;

        int coinCount;
        std::cin >> coinCount;

        for (int i = 0; i<coinCount; i++) {
            int currentCoin, currentCoinNum;
            std::cin >> currentCoin >> currentCoinNum;
            coin.insert(std::make_pair(currentCoin, currentCoinNum));
        }

        int consumption = 0;
        for (std::map<int, int>::reverse_iterator p = coin.rbegin(); p != coin.rend(); p++) {
            int n = std::min(m / p->first, p->second);
            m -= n * p->first;
            consumption += n;
        }
        if(m>0){
        	std::cout<<"Impossible\n";
		} else{
			std::cout << consumption << "\n";
		}
        std::cin >> m;
    }
    return 0;
}
