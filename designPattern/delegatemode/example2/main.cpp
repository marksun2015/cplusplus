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
	void f() {
		cout << "A::f()" << endl;
	}
};

class RemoteHostB : public Host
{
public:
	void f() {
		cout << "B::f()" << endl;
	}
};

// This class has a delegate switch to
// either RemoteHostA or RemoteHostB
class RemoteHost : public Host
{
public:
	explicit RemoteHost() 
	{ mHost = new RemoteHostA;}

    void f() { mHost->f(); }
 
    void connectA() { mHost = new RemoteHostA(); }
    void connectB() { mHost = new RemoteHostB(); }

private:
	Host *mHost;
};

int main()
{
    RemoteHost *remote = new RemoteHost();

    remote->f();         // A::f()

    remote->connectB();
    remote->f();         // B::f()

    remote->connectA();
    remote->f();         // A::f()

    return 0;
}

