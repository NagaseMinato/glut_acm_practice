#include <iostream>
#include <string>

void weirdPrint(int n) {
    for (int i = 0; i < n; i++) {
    	if(i>=7){
    		if (i % 7 == 0) {
	            std::cout << i << " ";
	        }
	        if (std::to_string(i).find("7") != std::string::npos) {
	            std::cout << i << " ";
	        }
		}
    }
}

int main() {
    int n;
    std::cin >> n;
    weirdPrint(n);
    return 0;
}
