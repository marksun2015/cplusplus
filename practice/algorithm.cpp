#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    vector<int> nums = {1, 5, 4, 2, 3, 8};

    auto it1 = std::find_if(nums.begin(), nums.end(), [] (int x) { return x % 2 == 0;} );
    if (it1 != nums.end())
        std::cout << "(% 2 == 0 ) " << *it1 << std::endl;
    
    auto it2 = std::find(nums.begin(), nums.end(), 4);
    if (it2 != nums.end()) {
        std::cout << "find ";
        std::cout << "it2 " << *it2 << std::endl;
    } else {
        std::cout << "not find " << std::endl;
    }
    
    auto it3 = std::min_element(nums.begin(), nums.end());
    std::cout << "min element " << *it3 << std::endl;


    int count_div4 = std::count_if(nums.begin(), nums.end(), [](int i) {return i % 4 == 0;});
    std::cout << "(% 4 == 0 ) " << count_div4 << std::endl;
    //std::sort(nums.begin(), nums.end(), std::greater<int>());    
    //std::sort(nums.begin(), nums.end()[](int a, int b){
    //            return a > b; 
    //            });    
    std::sort(nums.begin(), nums.end());
    for (auto n : nums) 
        std::cout << "n: " << n << std::endl;

    if (binary_search(nums.begin(), nums.end(), 5)) {
        cout << "Element found" << endl;
    }
    else {
        cout << "Element not found" << endl;
    }
}
