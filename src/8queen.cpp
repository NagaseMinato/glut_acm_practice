/* 8-queen problem

+ the golbal variable queen is used to store all solution, they would be printed 
later in main function;

+ as its name, queenCounter  just counts how many solutions of this problem

+ tempRow is used to store temporary solution,  if the final result yielded(i==8)
tempRow would be copied to solution matrix queen, which one row representing a
solution. there is a understandable tempRow figure:)
| 3 | row 1 column 3
| 5 | row 2 column 5
| 7 | row 3 column 7
| 8 | row 4 column 8
... so on


*/
#include <iostream>
#include <cmath>

int queen[1024][8];
int queenCounter = 0;
int tempRow[8] = { 0 };

void genQueen(int i) {
    if (i == 8) {
        queenCounter++;
        for (int x = 0; x < 8; x++) {
            queen[queenCounter][x] = tempRow[x];
        }
    }
    else {
        //for each column try to solve 
        for (int j = 0; j < 8; j++) {
            int m;
            for (m = 0; m < i; m++) {
                if (tempRow[m] == j || (std::abs(tempRow[m] - j) == std::abs(m-i))) {
                    break;
                }
            }
            if (m == i) {
                tempRow[m] = j;
                genQueen(i + 1);
            }
        }
    }
}

int main() {
    genQueen(0);
    std::cout << "there are " << queenCounter 
        << " solutions of 8-queen problem\n" << "they are as follows:\n";
    for (int i = 0; i < queenCounter; i++) {
        for (int k = 0; k < 8; k++){
            std::cout << queen[i][k] << " ";
        }
        std::cout << "\n";
    }
    getchar();
    return 0;
}
