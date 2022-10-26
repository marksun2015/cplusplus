#include<iostream>
#include<string>
#include<memory>
#include<map>

using namespace std;

enum OS_TYPE{
    Linux,
    Windows
};

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
                case Linux:
                    return std::make_unique<ProductA>("Linux");
                    break;
                case Windows:
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

    auto pap = f->createProduct(Linux);
    pap->operation();
    
    auto pbp = f->createProduct(Windows);
    pbp->operation();

    //std::map<int,std::unique_ptr <AbstractProduct>>

    return 0;
}

