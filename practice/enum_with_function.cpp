#include <map> 
#include <iostream> 

enum EnumType 
{ 
    enumOne, 
    enumTwo, 
    enumThree 
}; 

void showMessageOne() 
{ 
    std::cout << "This is message one" << std::endl;
} 

void showMessageTwo() 
{ 
    std::cout << "This is message two" << std::endl;
} 

void showMessageThree() 
{ 
    std::cout << "This is message three" << std::endl;
} 

int main() 
{ 
    //函数指针+std::map取代switch 
    typedef void (*func)(); 
    std::map<int,func> funcMap; 
    funcMap.insert(std::make_pair(enumOne, showMessageOne)); 
    funcMap.insert(std::make_pair(enumTwo, showMessageTwo)); 
    funcMap.insert(std::make_pair(enumThree, showMessageThree)); 
    funcMap[enumOne](); 
    funcMap[enumTwo](); 
    funcMap[enumThree](); 

    return 0; 
} 

