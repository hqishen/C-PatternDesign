#include <iostream>
/*
抽象工厂模式就是为了解决方法工厂模式生产单一对象的问题，抽象工厂模式可以生产一系列产品
*/
class Fruit {
public:
    virtual void name() = 0;
};

class Apple : public Fruit {
public:
    virtual void name() {
        std::cout << "Apple base" << std::endl;
    }
};

class Banana : public Fruit {
public:
    virtual void name() {
        std::cout << "Banana base" << std::endl;
    }
};

class ChinaApple : public Apple {
public:
    void name() {
        std::cout << "China Apple" << std::endl;
    }
};

class ChinaBanana : public Banana {
public:
    void name() {
        std::cout << "China Banana" << std::endl;
    }
};


class AbstractFactory {
public:
    virtual Fruit* createApple() = 0;
    virtual Fruit* createBanana() = 0;
};

class ChinaFactory : public AbstractFactory {
public:
    
    Fruit* createApple() {
        return new ChinaApple();
    }

    Fruit* createBanana() {
        return new ChinaBanana();
    }
};


int main()
{
    AbstractFactory * factory = new ChinaFactory();
    Fruit* apple = NULL, * banana = NULL;
    apple = factory->createApple();
    banana = factory->createBanana();

    apple->name();
    banana->name();
    delete apple;
    delete banana;

    return 0;
}

