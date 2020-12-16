#pragma once
#include <memory>

class BaseBox
{
public:
    virtual std::unique_ptr<BaseBox> Copy(void) = 0;
    virtual const std::type_info& GetType(void) = 0;
    virtual ~BaseBox(void) = default;
};

template <typename Object>
class Box : public BaseBox
{
private:
    Object object;

public:
    Box(const Object& other)
    {
        object = other;
    }
    ~Box(void) = default;

    std::unique_ptr<BaseBox> Copy(void) override
    {
        return std::make_unique<Box>(object);
    }

    Object GetObject(void)
    {
        return object;
    }

    const std::type_info& GetType(void) override
    {
        return typeid(object);
    }
};