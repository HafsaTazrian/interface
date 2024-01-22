#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
class Shape {
public:
    virtual void draw() = 0;
};
class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Inside Rectangle::draw() method." << std::endl;
    }
};
class Square : public Shape {
public:
    void draw() override {
        std::cout << "Inside Square::draw() method." << std::endl;
    }
};
class ShapeFactory {
private:
    static ShapeFactory* ins;
    ShapeFactory() {}
public:
    static ShapeFactory* getInstance() {
        if (ins == nullptr) {
            ins = new Singleton();
        }
        return ins;
    }
    static void releaseInstance() {
        if (ins != nullptr) {
            delete ins;
            ins = nullptr;
        }
    }

    Shape* getShape(const std::string& shapeType) {
        if (shapeType.empty()) {
            return nullptr;
        }

        if (shapeType == "RECTANGLE") {
            return new Rectangle();
        } else if (shapeType == "SQUARE") {
            return new Square();
        }

        return nullptr;
    }
};

ShapeFactory* ShapeFactory::ins = nullptr;
int main()
{
    ShapeFactory* x = ShapeFactory::getInstance();
    Shape* shape1 = x.getShape("CIRCLE");
    if (shape1 != nullptr) {
        shape1->draw();
        delete shape1;
    }

    Shape* shape2 = x.getShape("RECTANGLE");
    if (shape2 != nullptr) {
        shape2->draw();
        delete shape2;
    }

    return 0;
    
}