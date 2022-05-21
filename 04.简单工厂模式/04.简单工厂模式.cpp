
#include <iostream>

/*
不符合开闭原则，不是标准的设计模式
*/
class AbstractShape {
public:
    virtual void area() = 0;
};

class Triangle : public AbstractShape {
public:
    Triangle(int h = 10, int w = 20) : m_h(h), m_w(w) {
    }

    void area() {
        std::cout << "area:" << m_h * m_w / 2 << std::endl;
    }

private:
    int m_h;
    int m_w;
};

class Round : public AbstractShape {
public:
    Round(int r=3) :m_r(r) {

    }
    void area() {
        std::cout << "round area:" << m_r * m_r / 2 << std::endl;
    }
private:
    int m_r;
};

class Factory {
public:
    AbstractShape* createShape(int i) {
        if (i == 0) {
            return new Triangle();
        }
        else if (i == 1) {
            return new Round();
        }
    }
};

int main()
{
    Factory* factory = new Factory();
    AbstractShape* shape = factory->createShape(0);
    shape->area();
    delete shape;
    shape = factory->createShape(1);
    shape->area();
    delete shape;
}
