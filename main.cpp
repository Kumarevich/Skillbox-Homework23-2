#include <iostream>

#define FUNCTION(name1, name2) name1 ## _ ## name2

void function_calculate(int* a, int i, int sum) {
    if (i < 11) {
        sum += (*a);
        ++i;
        FUNCTION (function, calculate) (a + 1, i, sum);
    } else {
        std::cout << sum;
    }
}

void function_notfill(int* a, int i) {
    if (i > 0) {
        if (*a < 20) std::cout << i << std::endl;
        --i;
        FUNCTION (function, notfill) (a - 1, i);
    } else {
        FUNCTION (function, calculate) (a + 1, i + 1, 0);
    }
}

void function_overfill(int* a, int i) {
    if (i < 11) {
        if (*a > 20) std::cout << i << std::endl;
        i++;
        FUNCTION (function, overfill) (a + 1, i);
    } else {
        FUNCTION (function, notfill) (a - 1, i - 1);
    }
}

int main() {
    int a[10] = {11, 9, 5, 20, 25, 16, 24, 30, 19, 20};
    FUNCTION (function, overfill) (a, 1);
    return 0;
}
