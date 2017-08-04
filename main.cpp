#include <iostream>

#include "Date.h"
int main() {
    Date d;

    std::cout << d.getDay()<<d.getMonth()<<d.getYear() << std::endl;
    Date f(4,15,2017);
    if (f==d)
        std::cout<<"true";
    return 0;
}
