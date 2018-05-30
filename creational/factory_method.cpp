#include <iostream>
#include <cassert>

//virtual inheritance if still virtual, yes
//override final keyword, c++ 11. 

class Product {
public:
    virtual void dis() = 0;
};

class ConcreteProductA : public Product {
public:
    void dis() override {
        std::cout << "ConcreteProductA" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void dis() override {
        std::cout << "ConcreteProductB" << std::endl;
    }
};


class Creator {
public:
    virtual class Product* factory_method() = 0;
};

template <typename T>
class ConcreteCreatorA : public Creator {
public:
    class Product* factory_method() override {
        return (new ConcreteProductA());
    }    
};

class ConcreteCreatorB : public Creator {
public:
    class Product* factory_method() override {
        return (new ConcreteProductB());
    }  
};



int main()
{
    ConcreteCreatorA a;
    ConcreteCreatorB b;
#if 0
    Creator *ptr = nullptr;
    ptr = new ConcreteCreatorA();
    ptr->factory_method()->dis();
    ptr = new ConcreteCreatorB();
    ptr->factory_method()->dis();
#else
    a.factory_method()->dis();
    b.factory_method()->dis();
#endif
    return 0;
    
}
