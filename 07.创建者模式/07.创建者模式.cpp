#include <iostream>

class House {
public:
    virtual void buildFloor(std::string floor) {
        std::cout << "build " <<  floor << " ffloor" << std::endl;
    }
    virtual void buildWall(std::string wall) {
        std::cout << "build " << wall << " wall" << std::endl;
    }
    virtual void buildDoor(std::string door) {
        std::cout << "build " << door << " door" << std::endl;
    }


private:
    std::string m_floor;
    std::string m_wall;
    std::string m_door;
};


class Builder {
public:
    virtual void makeFloor() = 0;
    virtual void makeWall() = 0;
    virtual void makeDoor() = 0;
    virtual House* getHouse() = 0;
};

/*
创建各种各样的工程队
*/
class FlatBuilder : public Builder {
public:
    FlatBuilder() {
        m_house = new House();
    }

    ~FlatBuilder() {
        delete m_house;
    }

    void makeFloor() {
        m_house->buildFloor("flat");
    }

    void makeWall() {
        m_house->buildWall("flat");
    }

    void makeDoor() {
        m_house->buildDoor("flat");
    }

    House* getHouse() { return m_house; }
private:
    House* m_house;
};

class Villa : public Builder {
public:
    Villa() {
        m_house = new House();
    }
    ~Villa() {
        delete m_house;
    }
    void makeFloor() {
        m_house->buildFloor("villa");
    }
    void makeDoor() {
        m_house->buildDoor("valla");
    }
    House* getHouse() { return m_house; }
private:
    House* m_house;
};

#include <cassert>
class Director {
public:
    void Construct(Builder* builder) {
        assert(builder);
        builder->makeDoor();
        builder->makeFloor();
        builder->makeWall();
    }
};

int main()
{
    Builder* builder = new FlatBuilder();
    Director* director = new Director();
    director->Construct(builder);
    return 0;
}
