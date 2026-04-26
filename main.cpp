#include "array.h"
#include <iostream>

int main() {
    Array myArr(3, 5);

    myArr.setValue(10);
    myArr.setValue(20);
    myArr.setValue(30);

    myArr.setValue(40);

    int extra[] = { 100, 200, 300 };
    myArr.setArray(extra, 3);

    std::cout << "Elements: ";
    myArr.showElements();
    std::cout << "Real size: " << myArr.getElemSize() << std::endl;
    std::cout << "Size: " << myArr.getSize() << std::endl;

    return 0;
}