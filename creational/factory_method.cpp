#include <iostream>
#include <cassert>

//virtual inheritance if still virtual, yes
//override final keyword, c++ 11. 
//abstract class difinition, c++ primer p597. pure virtual class

namespace gof {
namespace creational {

class Product {
public:
    virtual void dis(){};
    virtual ~Product(){};
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
    Product* get_product() {
        if(nullptr == _product) {
           _product =  create_product();
        }

        return _product;
    }

    void destory_product() {
        if(_product) {
            delete _product;
            _product = nullptr;
        }
    }
    virtual ~Creator(){};
    
protected:
    Creator() : _product(nullptr) {}   
    virtual Product* create_product() {
        return (new Product());
    }; 
private:
    class Product* _product;
};

class ConcreteCreatorA : public Creator {
public:
    ConcreteCreatorA() {}
protected:
    virtual Product* create_product() final {
        return (new ConcreteProductA());
    }  
};

class ConcreteCreatorB : public Creator {
public:
    ConcreteCreatorB() {}
protected:
    virtual Product* create_product() final {
        return (new ConcreteProductB());
    }  
};


}
}

using gof::creational::ConcreteCreatorA;
using gof::creational::ConcreteCreatorB;
using gof::creational::Creator;


int main()
{
    Creator *creator = nullptr; 
    creator = new ConcreteCreatorA();
    assert(creator);    
    creator->get_product()->dis();
    creator->destory_product();
    delete creator;
    
    creator =  nullptr;
    creator = new ConcreteCreatorB();
    assert(creator);      
    creator->get_product()->dis();
    creator->destory_product();
    delete creator;
    
    return 0;
    
}
