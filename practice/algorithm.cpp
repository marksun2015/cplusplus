#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    auto it1 = find_if(nums.begin(), nums.end(), [] (int x) { return x % 2 == 0;} );
    if (it1 != nums.end())
        std::cout << "it1 " << *it1 << std::endl;
    
    auto it2 = find(nums.begin(), nums.end(), 4);
    if (it2 != nums.end()) {
        std::cout << "find ";
        std::cout << "it2 " << *it2 << std::endl;
    } else {
        std::cout << "not find " << std::endl;
    }
}
