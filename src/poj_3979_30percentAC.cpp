#include <cstdio>
#include <map>
#include <iostream>
#include <string>
#include <cctype>

// @summary 计算 a op b
// @param int a 
// @param int b
// @return int 返回a op b
int doComputing(int a, int b, char op) {
    switch (op) {
    case '+':return a + b;
    case '-':return a - b;
    //default:
    //    throw std::exception("unsupport opcode\n");
    }
    return 0;
}

// @summary 给出两个数，寻找这两个数的最大公因数
// @param int a 数A
// @param int b 数B
// @return int A和B的最大公因数
int findGreatestCommonFactor(int a, int b) {
    int i = 1;
    while (i%a != 0 || i%b != 0) {
        i++;
    }
    return i;
}

// @summary 将分数转化为以最大公因数为底的分数形式
// @param int a 分子
// @param int b 分母
// @param int greatestCommonFactor 最大公因数
// @return pair<int,int> 以最大公因数为底的分数
std::pair<int, int> transformFraction(int a, int b, int greastestCommonFactor) {
    int n = greastestCommonFactor / b;
    a *= n;
    return std::make_pair(a, greastestCommonFactor);
}

// @summary 返回a/b化简后的记过
// @param int 分子
// @param int 分母
// @return pair<int,int> 化简后的a/b
std::pair<int,int> simplifyFraction(int a, int b) {
    int max = 0;
    for (int i = 1; i <= (a > b ? a : b); i++) {
        if (a%i == 0 && b%i == 0) {
            max = i;
        }
    }
    return std::make_pair(a / max, b / max);
}

void parseNumbersFrom(std::string const & str, int *a1, int *a2, int *b1, int *b2, char *op) {
    int firstDiv = str.find_first_of('/');
    int secondDiv = str.find_last_of('/');
    *a1 = atoi(str.substr(0, firstDiv).c_str());
    int start = firstDiv;
    if (str[++start] == '-') {
        start++;
    }
    while (str[start] != '+' && str[start] != '-')start++;
    *a2 = atoi(str.substr(firstDiv+1, start-firstDiv).c_str());
    *op = str[start];
    *b1 = atoi(str.substr(start + 1, secondDiv-start-1).c_str());
    *b2 = atoi(str.substr(secondDiv+1).c_str());

    if (*a2 < 0) {
        *a2 = -(*a2);
        *a1 = -(*a1);
    }
    if (*b2 < 0) {
        *b2 = -(*b2);
        *b1 = -(*b1);
    }
}

int main() {
    std::string str;
    while (!std::cin.eof()) {
        std::string str;
        std::cin >> str;

        int a1, a2;
        int b1, b2;
        char opcode;
        parseNumbersFrom(str, &a1, &a2, &b1, &b2, &opcode);

        int greatestCommonFactor = findGreatestCommonFactor(a2, b2);
        std::pair<int, int> x1 = transformFraction(a1, a2, greatestCommonFactor);
        std::pair<int, int> x2 = transformFraction(b1, b2, greatestCommonFactor);
        int result1 = doComputing(x1.first, x2.first, opcode);

        if (result1 < 0) {
            std::pair<int, int> r = simplifyFraction(-result1, greatestCommonFactor);
            if (r.second != 1) {
                printf("-%d/%d\n",
                    r.first,
                    r.second);
            }
            else {
                printf("-%d\n", r.first);
            }
        }
        else if (result1 > 0) {
            std::pair<int,int> r = simplifyFraction(result1, greatestCommonFactor);
            if (r.second != 1) {
                printf("%d/%d\n",
                    r.first,
                    r.second);
            }
            else {
                printf("%d\n", r.first);
            }
        }
        else {
            printf("0\n");
        }
    }
   
    return 0;
}