#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    vector<int> ivec1(10);    // 宣告1個vector，裡面有10個int空間。
    vector<int> ivec2[10];   // 宣告10個vector，每一個都可以存int。
    
    vector<int> ivec3 = {1,2,3,4,5,6,7,8,9,10}; //記下來,assign方式  
    ivec3[8] = 8;
    ivec3[9] = 8;
    
    vector<string> ivec4 = {"aaa","bbb"}; //記下來,assign方式  

    ivec1[0] = 1;
    ivec1[1] = 2;
    ivec1[2] = 3;
    ivec1.push_back(4);  // 宣告1個vector，裡面有10個int空間。

    vector<int> ivec5(ivec3.begin(), ivec3.end()); //記下來,assign方式

    std::cout << "---1-------------------" << std::endl;
    for (auto &elem : ivec1) {
        std::cout << &elem << std::endl;
        if (&elem == &ivec1[0])
            elem = 9;
    }
    //std::cout << "begin " << ivec1.begin() << std::endl;

    for(int i = 0; i < ivec1.size(); i++)
        std::cout << ivec1[i] << std::endl;
    
    for (auto elem : ivec1)
        std::cout << elem << std::endl;

    std::cout << "---2-------------------" << std::endl;
    std::cout << std::endl;
    for (auto &elem : ivec1)
        std::cout << elem << std::endl;
    
    std::cout << "---3-------------------" << std::endl;
    std::cout << std::endl;
    for (auto &elem : ivec1)
        elem = 5;

    std::cout << "---4-------------------" << std::endl;
    for (auto elem : ivec5)
        std::cout << elem << std::endl;
}
