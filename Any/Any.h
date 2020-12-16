#pragma once
#include "Boxes.h"

class Any
{
private:
    std::unique_ptr<BaseBox>* array;
    std::size_t size;

public:
    Any(void);
    Any(const Any& other);
    ~Any(void);

    void Swap(Any& object1, Any& object2);
    Any& operator= (Any other);

    template<typename Type>
    void Append(Type object)
    {
        std::unique_ptr<BaseBox>* temp = new std::unique_ptr<BaseBox>[++size];

        for (std::size_t i = 0; i < size - 1; ++i)
            temp[i] = array[i]->Copy();
        temp[size - 1] = std::make_unique<Box<Type>>(object);

        delete[] array;
        array = temp;
    }

    template<typename Type>
    void GetValue(std::size_t index, Type& destination)
    {
        if (index >= size)
            return;
        if (typeid(destination) == array[index]->GetType())
        {
            destination = static_cast<Box<Type>*>(array[index].get())->GetObject();
            return;
        }
        std::cout << "No matching value found" << std::endl;
    }
};