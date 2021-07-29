//https://www.bogotobogo.com/DesignPatterns/delegation.php

#include <iostream>
using namespace std;

class Host
{
public:
	virtual void f() = 0;
};

class RemoteHostA : public Host
{
public:
	void f() override {
        //Remote host A 做的事情
		cout << "A::f()" << endl;
	}
};

class RemoteHostB : public Host
{
public:
	void f() override {
        //Remote host B 做的事情
		cout << "B::f()" << endl;
        //委託不同host做f()，但是，每個host f()做的事情會不一樣
	}
};

// This class has a delegate switch to
// either RemoteHostA or RemoteHostB
class RemoteHost : public Host
{
public:
	explicit RemoteHost() 
	{
        mHost_ = new RemoteHostA;
    }

    void f() {
        mHost_->f();
    }
 
    void connectA() { mHost_ = new RemoteHostA(); }
    void connectB() { mHost_ = new RemoteHostB(); }

private:
	Host *mHost_;
};

int main()
{
    RemoteHost *remote = new RemoteHost();

    remote->f();         // A::f()

    remote->connectB();  // 可以改成create  ex:remote->createB()
    remote->f();         // B::f()

    remote->connectA();  // 可以改成create  ex:remote->createA()
    remote->f();         // A::f()

    return 0;
}

