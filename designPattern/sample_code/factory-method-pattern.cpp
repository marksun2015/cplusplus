#include <iostream>
#include <string>

using namespace std;

/*
 * Define an interface for creating an object, but let 
 * subclasses decide which class to instantiate. 
 */
 
class Shape {
    public:
       virtual void Draw() = 0;
       static Shape* ShapeFactory(string type);
};

class Circle : public Shape {
    public:
       void Draw() { cout << "I am circle" << endl; }
       friend class Shape;
};

class Square : public Shape {
    public:
       void Draw() { cout << "I am square" << endl; }
       friend class Shape;
};

class Rectangle : public Shape {
    public:
       void Draw() { cout << "I am rectangle " << endl; }
       friend class Shape;
};

Shape* Shape::ShapeFactory(string type) {
    if ( type == "circle" ) return new Circle();
    if ( type == "square" ) return new Square();
    if ( type == "rectangle" ) return new Rectangle();
    return NULL;
}

int main(){
   Shape* obj1 = Shape::ShapeFactory("circle");
   Shape* obj2 = Shape::ShapeFactory("square");
   Shape* obj3 = Shape::ShapeFactory("rectangle");
   obj1->Draw();
   obj2->Draw();
   obj3->Draw();
}
