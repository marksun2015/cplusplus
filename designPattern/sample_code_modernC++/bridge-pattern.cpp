/*
* http://www.vishalchovatiya.com/bridge-design-pattern-in-modern-cpp/
*/

#include <iostream>
using namespace std;

struct DrawingAPI {
    virtual void drawCircle() = 0;
};
struct DrawingAPI_1 : DrawingAPI {
    void drawCircle() { cout << "Drawn by API 1"<< endl; }
};
struct DrawingAPI_2 : DrawingAPI {
    void drawCircle() { cout << "Drawn by API 2"<< endl; }
};
struct Shape {
    Shape(DrawingAPI &drawingAPI) : m_drawingAPI{drawingAPI} {}
    virtual void draw() = 0;
    protected:
    DrawingAPI &m_drawingAPI;   // Now Shapes does not need to worry about drawing APIs
};
struct Circle : Shape {
    Circle(DrawingAPI &drawingAPI) : Shape{drawingAPI} {}
    void draw() { m_drawingAPI.drawCircle(); }
};
int main() {
    DrawingAPI_1 API_1;
    DrawingAPI_2 API_2;
    Circle(API_1).draw();
    Circle(API_2).draw();
    return EXIT_SUCCESS;
}
