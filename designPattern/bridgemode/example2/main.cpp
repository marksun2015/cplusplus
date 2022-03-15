#include <iostream>
using namespace std;

class software
{
    public:
        software(){}
        virtual ~software(){}
        virtual void exec()=0;
};

class game : public software
{
    public:
        game(){}
        virtual ~game(){}
        void exec(){cout<<"play game"<<endl;}
};

class office : public software
{
    public:
        office(){}
        virtual ~office(){}
        void exec(){cout<<"work office"<<endl;}
};

class computer
{
    public:
        computer():_instance(NULL){}
        virtual ~computer(){}
        void setsoftware(software *instance){_instance=instance;}
        virtual void Exec()=0;

    protected:
        software *_instance;
};

class wincomputer : public computer
{
    public:
        wincomputer(){}
        virtual ~wincomputer(){}
        void Exec(){cout<<"win  ";_instance->exec();}
};

class maccomputer : public computer
{
    public:
        maccomputer(){}
        virtual ~maccomputer(){}
        void Exec(){cout<<"mac  ";_instance->exec();}
};

int main()
{
    computer *pc=new wincomputer;
    software *ps=new office;
    pc->setsoftware(ps);
    pc->Exec();
    delete ps;
    delete pc;

    pc=new maccomputer;
    ps=new game;
    pc->setsoftware(ps);
    pc->Exec();
    delete ps;
    delete pc;

    system("pause");
    return 0;
}
