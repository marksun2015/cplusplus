#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    vector<int> ivec1(10);    // 宣告1個vector，裡面有10個int空間。
    vector<int> ivec2[10];   // 宣告10個vector，每一個都可以存int。

    ivec1[0] = 1;
    ivec1[1] = 2;
    ivec1[2] = 3;
    ivec1.push_back(4);  // 宣告1個vector，裡面有10個int空間。

    for (auto elem : ivec1)
        std::cout << elem << std::endl;
}
