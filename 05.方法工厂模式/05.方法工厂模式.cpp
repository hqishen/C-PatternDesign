// 05.方法工厂模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
只能生产单一的产品，不能生产一个产品组，所以就需要添加抽象工厂模式
*/

#include <iostream>

class Shape {
public:
    virtual void area() = 0;
};

class Round : public Shape {
public:
    Round(int r = 9) : m_r(r) {

    }

    void area() {
        std::cout << "Round area is :" << m_r * m_r / 2 << std::endl;
    }

private:
    int m_r;
};

class Triangle : public Shape {
public:
    Triangle(int h = 4, int w = 4) :m_h(h), m_w(w) {

    }

    void area() {
        std::cout << "Triangle area :" << m_w * m_h << std::endl;
    }
private:
    int m_h;
    int m_w;
};

class AbstractFactory {
public:
    virtual Shape* createShape() = 0;
};

class TriangleFactory : public AbstractFactory {
public:
    Shape* createShape() {
        return new Triangle();
    }
};

class RoundFactory : public AbstractFactory {
public:
    Shape* createShape() {
        return new Round();
    }
};

int main() {
    AbstractFactory* factory = new TriangleFactory();
    Shape * shape = factory->createShape();
    shape->area();
    delete shape;
    delete factory;
    return 0;
}
