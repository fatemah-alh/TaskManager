#include <iostream>

#include "Date.h"
int main() {
    Date d;

    std::cout << d.getDay()<<d.getMonth()<<d.getYear() << std::endl;
    return 0;
}