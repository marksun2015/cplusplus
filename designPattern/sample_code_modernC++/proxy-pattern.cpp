/*
* http://www.vishalchovatiya.com/proxy-design-pattern-in-modern-cpp/
*/

#include <iostream>
using namespace std;

struct Image {
    virtual void draw() = 0;
};

struct Bitmap : Image {
    Bitmap(const string &filename) : m_filename(filename) {
        cout << "Loading image from " << m_filename << endl;
        // Steps to load the image
    }
    void draw() { cout << "Drawing image " << m_filename << endl; }
    string      m_filename;
};

int main() {
    Bitmap img_1{"image_1.png"};
    Bitmap img_2{"image_2.png"};
    //(rand() % 2) ? img_1.draw() : img_2.draw();
    img_1.draw(); 
    img_2.draw();
    return EXIT_SUCCESS;
}
