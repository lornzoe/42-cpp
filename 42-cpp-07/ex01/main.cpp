#include <iostream>
#include "iter.hpp"

void printInt(int &x) { x += 1; std::cout << x << " "; }
void printStr(std::string &s) { s += "!"; std::cout << s << " "; }

int main() {
    int arr[] = {1, 2, 3, 4};
    iter<int>(arr, 4, printInt);
    std::cout << std::endl;

    std::string sarr[] = {"a", "b", "c"};
    iter<std::string>(sarr, 3, printStr);
    std::cout << std::endl;

    return 0;
}
