#include <iostream>
using namespace std;
class Power {
    int kick;
    int punch;
    public:
        Power(int kick = 0, int punch = 0) {
            this->kick = kick; 
            this->punch = punch;
        }
        void show();
        Power& operator<<(int n);
    
    public:
        int fkick;
        int fpunch;
        
    friend Power operator+(Power op1, Power op2);
};

void Power::show() {
    cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power& Power::operator<<(int n) {
    kick += n;
    punch += n;
    return *this;
}

Power operator+(Power op1, Power op2) {
    Power tmp;
    tmp.kick = op1.kick + op2.kick;
    tmp.punch = op1.punch + op2.punch;
    return tmp;
}

int main() {
    //Power a(1, 2);
    //a << 3 << 5 << 6;

    Power a(3, 5), b(4, 6), c;
    c = a + b;
    a.show();
    b.show();
    c.show();
}
