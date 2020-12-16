#include <iostream>
#include "Any.h"

Any::Any(void)
{
    array = nullptr;
    size = 0;
}

Any::Any(const Any& other)
{
    size = other.size;
    if (other.array == nullptr)
    {
        array = nullptr;
        return;
    }

    array = new std::unique_ptr<BaseBox>[size];
    for (std::size_t i = 0; i < other.size; ++i)
        array[i] = other.array[i]->Copy();
}

Any::~Any(void)
{
    delete[] array;
}

void Any::Swap(Any& object1, Any& object2)
{
    std::swap(object1.array, object2.array);
    std::swap(object1.size, object2.size);
}

Any& Any::operator= (Any other)
{
    Swap(*this, other);
    return *this;
}