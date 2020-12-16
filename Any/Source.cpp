#include <iostream>
#include "Any.h"

int main(void)
{
    Any array1;
    Any array2;

    array1.Append(5);
    array1.Append("Hello!");
    array2.Append(4);

    int x = 0;
    array1.GetValue(0, x);
    std::cout << "The first element in array1: " << x << std::endl;

    array1 = array2;
    array1.GetValue(0, x);
    std::cout << "The first element in array1 after swapping: " << x << std::endl;

    return 0;
}