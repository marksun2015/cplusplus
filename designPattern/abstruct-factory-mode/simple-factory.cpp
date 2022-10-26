#include<iostream>
#include<string>
#include<memory>

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

        void operation() override
        {
            cout << "ProductA::Operation() show name:" << mname << endl;
        }
};

class ProductB : public AbstractProduct
{
    public:
        ProductB(string name) :AbstractProduct(name){}
        ~ProductB(){}

        void operation() override
        {
            cout << "ProductB::Operation() show name:" << mname << endl;
        }
};

class Factory
{
    public:
        std::unique_ptr <AbstractProduct> createProduct(int os)
        {
            switch (os)
            {
                case 1:
                    return std::make_unique<ProductA>("Linux");
                    break;
                case 2:
                    return std::make_unique<ProductB>("Windows");
                    break;
                default:
                    return NULL;
                    break;
            }
        }
};

int main()
{
    std::unique_ptr <Factory> f = std::make_unique <Factory>();

    auto pap = f->createProduct(1);
    pap->operation();
    
    auto pbp = f->createProduct(2);
    pbp->operation();

    return 0;
}

