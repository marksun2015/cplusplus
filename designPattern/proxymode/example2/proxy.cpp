#include "proxy.h"
#include <iostream>

using namespace std;

Subject::Subject()
{

}

Subject::~Subject()
{

}

ConcreteSubject::ConcreteSubject()
{

}

ConcreteSubject::~ConcreteSubject()
{

}

void ConcreteSubject::Request()
{
    cout << "ConcreteSubject::Request" << endl;
}

Proxy::Proxy() : _subject(NULL)
{

}

Proxy::~Proxy()
{

}

void Proxy::DoSomething1()
{
    cout << "Proxy::DoSomething1" << endl;
}

void Proxy::DoSomething2()
{
    cout << "Proxy::DoSomething2" << endl;
}

void Proxy::Request()
{
    if(NULL == this->_subject)
    {
        this->_subject = new ConcreteSubject();
    }

    this->DoSomething1();//Indicates additional additional actions

    this->_subject->Request();//Agent entity class operation

    this->DoSomething2();//Indicates additional additional actions
}
