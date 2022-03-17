#include <iostream>
using namespace std;

class Computer
{
    public:
        virtual void display()
        {
            cout << "I am a computer..." << endl;
        }
};

class CDDrive : public Computer
{
    private:
        Computer* c;
    public:
        CDDrive(Computer* _c)
        {
            c = _c;
        }
        void display()
        {
            c->display();
            cout << "with a CD Drive..." << endl;
        }
};

class Printer : public Computer
{
    private:
        CDDrive* d;
    public:
        Printer(CDDrive* _d)
        {
            d = _d;
        }
        void display()
        {
            d->display();
            cout << "with a printer..." << endl;
        }
};

int main()
{
    Computer* c = new Computer();
    CDDrive* d = new CDDrive(c);
    Printer* p = new Printer(d);

    p->display();
}
