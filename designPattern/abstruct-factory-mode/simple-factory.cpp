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

#if 1
    auto pap = f->createProduct(Linux);
    pap->operation();
    
    auto pbp = f->createProduct(Windows);
    pbp->operation();
#else
    std::map<int,std::unique_ptr <AbstractProduct>> os_map;
    os_map.insert(std::make_pair(Linux, f->createProduct(Linux)));
    os_map.insert(std::make_pair(Windows, f->createProduct(Windows)));
    os_map[Linux]->operation();
    os_map[Windows]->operation();
#endif

    return 0;
}

