#include <iostream>
#include <cassert>

//virtual inheritance if still virtual, yes
//override final keyword, c++ 11. 
//abstract class difinition, c++ primer p597. pure virtual class

namespace gof {
namespace creational {

class AbstractProductA {
public:
    virtual void dis(){};
    virtual ~AbstractProductA(){};
};

class AbstractProductB {
public:
    virtual void dis(){};
    virtual ~AbstractProductB(){};
};


class ConcreteProductA1 : public AbstractProductA {
public:
    void dis() override {
        std::cout << "ConcreteProductA1" << std::endl;
    }
};

class ConcreteProductB1 : public AbstractProductB {
public:
    void dis() override {
        std::cout << "ConcreteProductB1" << std::endl;
    }
};


class ConcreteProductA2 : public AbstractProductA {
public:
    void dis() override {
        std::cout << "ConcreteProductA2" << std::endl;
    }
};

class ConcreteProductB2 : public AbstractProductB {
public:
    void dis() override {
        std::cout << "ConcreteProductB2" << std::endl;
    }
};



class Creator {
public:
    AbstractProductA* get_productA() {
        if(nullptr == _productA) {
           _productA =  create_productA();
        }

        return _productA;
    }

    AbstractProductB* get_productB() {
        if(nullptr == _productB) {
           _productB =  create_productB();
        }

        return _productB;
    }

    void destory_productA() {
        if(_productA) {
            delete _productA;
            _productA = nullptr;
        }
    }
    
    void destory_productB() {
        if(_productB) {
            delete _productB;
            _productB = nullptr;
        }
    }

    virtual ~Creator(){};
    
protected:
    Creator() : _productA(nullptr), _productB(nullptr) {}   
    virtual AbstractProductA* create_productA() {
        return (new AbstractProductA());
    }; 
    virtual AbstractProductB* create_productB() {
        return (new AbstractProductB());
    }; 

private:
    class AbstractProductA* _productA;
    class AbstractProductB* _productB;

};

class ConcreteCreator1 : public Creator {
public:
    ConcreteCreator1() {}
protected:
    virtual AbstractProductA* create_productA() final {
        return (new ConcreteProductA1());
    }  
    virtual AbstractProductB* create_productB() final {
        return (new ConcreteProductB1());
    }  

};

class ConcreteCreator2 : public Creator {
public:
    ConcreteCreator2() {}
protected:
    virtual AbstractProductA* create_productA() final {
        return (new ConcreteProductA2());
    }  
    virtual AbstractProductB* create_productB() final {
        return (new ConcreteProductB2());
    }  
};


}
}

using gof::creational::ConcreteCreator1;
using gof::creational::ConcreteCreator2;
using gof::creational::Creator;


int main()
{
    Creator *creator = nullptr; 
    creator = new ConcreteCreator1();
    assert(creator);    
    creator->get_productA()->dis();
    creator->get_productB()->dis();
    creator->destory_productA();
    creator->destory_productB();
    delete creator;
    
    creator =  nullptr;
    creator = new ConcreteCreator2();
    assert(creator);      
    creator->get_productA()->dis();
    creator->get_productB()->dis();
    creator->destory_productA();
    creator->destory_productB();
    delete creator;
    
    return 0;
    
}
