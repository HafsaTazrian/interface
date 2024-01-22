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
int main()
{
    
}