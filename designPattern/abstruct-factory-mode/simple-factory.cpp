#include<iostream>
using namespace std;

class AbstractProduct
{
    public:
        AbstractProduct(string name) :mname(name){}
        virtual void operation() = 0;
        virtual ~AbstractProduct(){}
    protected:
        string mname;
};
class ProductA : public AbstractProduct
{
    public:
        ProductA(string name) :AbstractProduct(name){}
        ~ProductA(){}
        virtual void operation()
        {
            cout << "ProductA::Operation()" << endl;
        }
};
class ProductB : public AbstractProduct
{
    public:
        ProductB(string name) :AbstractProduct(name){}
        ~ProductB(){}
        virtual void operation()
        {
            cout << "ProductB::Operation()" << endl;
        }
};
class Factory
{
    public:
        AbstractProduct* createProduct(int flag)
        {
            switch (flag)
            {
                case 1:
                    return new ProductA("A");
                    break;
                case 2:
                    return new ProductB("B");
                    break;
                default:
                    return NULL;
                    break;
            }
        }
};

int main()
{
    Factory f;
    AbstractProduct* pap = f.createProduct(1);
    pap->operation();
    AbstractProduct* pbp = f.createProduct(2);
    pbp->operation();
    delete pap;
    delete pbp;

    return 0;
}

