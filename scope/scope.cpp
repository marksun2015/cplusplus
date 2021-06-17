/*
    http://jasonblog.github.io/note/c++/cjing_tai_cheng_yuan_han_shu_fang_wen_fei_jing_tai.html 
 */

#include <iostream>
using namespace std;

class A
{
    public:
        A()
        {
            cout << "A class" << endl;
            m_a = 100;
            //靜態成員函數不能存取非靜態成員，但別忘了，他們可以存取靜態成員，
            //也就是說，如果我們的這個類是個單例，我們完全可以在創建的時候  
            //把this指針賦值給那個靜態成員，然後在靜態成員函數內部就可以放心大膽的使用了。
            m_gA = this;
        }
        static void test()
        {
            cout << "test()"<< endl;
            m_gA->m_a += 1;
        }
        void show()
        {
            cout << "show()"<< endl;
            cout << m_a << endl;
        }
        static int m_staticA;
        static A* m_gA;
    private:
        int m_a;
};

A* A::m_gA = nullptr;
//int A::m_staticA = 0;

int main()
{
    A a;
    //在還沒有new的時候, 需要有static宣告才可以直接用function, 如下A::test()
    //function裡面也只能用 static宣告的變數. 
    //如果沒有A a; 直接使用A::test(), 編譯不會過, 
    A::test();
    a.show();
    return 0;
}
