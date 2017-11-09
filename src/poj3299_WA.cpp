#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>

double res[1024][10];

double getHumidex(double t, double d) {
    double e = 6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (d + 273.16))));
    double h = (0.5555)* (e - 10.0);
    return t + h;
}


int main() {
    std::string str;
    std::getline(std::cin, str);
    int count = 0;
    while (str != "E") {
        count++;
        double t, d;
        sscanf(str.c_str(), "T %lf D %lf", &t, &d);
        res[count][0] = t;
        res[count][1] = d;
        res[count][2] = getHumidex(t, d);
        std::getline(std::cin, str);
    }
    for (int i = 0; i<count; i++) {
        if(count!=1){
            printf("T %.1f D %.1f H %.1f\n", res[i + 1][0], res[i + 1][1], res[i + 1][2]);
        }
       
    }
    return 0;
}
