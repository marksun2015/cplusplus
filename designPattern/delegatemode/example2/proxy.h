#ifndef _PROXY_H_
#define _PROXY_H_

//  Defines the public interface of Proxy and ConcreteSubject.
//  This way you can use Proxy anywhere you need to use ConcreteSubject.
class Subject
{
    public:
        virtual ~Subject();
        virtual void Request()=0;
    protected:
        Subject();
};

class ConcreteSubject : public Subject
{
    public:
        ConcreteSubject();
        ~ConcreteSubject();
        virtual void Request();
};

//Defining a proxy class
class Proxy : public Subject
{
    public:
        Proxy();
        ~Proxy();
        void DoSomething1();
        virtual void Request();
        void DoSomething2();
    private:
        Subject* _subject;
};
#endif
