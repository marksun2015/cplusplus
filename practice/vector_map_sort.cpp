#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

//直接宣告
std::map<int, std::string> studentMap = {
    {1, "Tom"},
    {3, "Jack"},
    {6, "John"}
};

void sort_price(std::map<string, int> &strmap, vector<pair<string, int>> &vec) {
  vec = {strmap.begin(), strmap.end()};
  sort(vec.begin(), vec.end(),
    [](auto x, auto y) { return x.second < y.second; });
}
    
int main() {
    std::map <string, int> mp_price;
    std::vector <pair<string, int>> book_table;

    mp_price.insert({"HarryPoter", 500});
    mp_price.insert({"WebWorld", 400});
    mp_price.insert({"DuckLife", 300});
    mp_price.insert(std::make_pair("Java",250));

    book_table = {mp_price.begin(), mp_price.end()}; //記下來, assign 方式

    //sort_price(mp_price, book_table);
    
    book_table.push_back(std::make_pair("C++Primer",650)) ;

    sort(book_table.begin(), book_table.end(),
            [](auto x, auto y){
                return x.second < y.second;
              });

    for(auto bt : book_table)
        std::cout << bt.first << " " << bt.second << std::endl;

    ///////////////////////////////////////////////////////////////
    map <string, int> price;
    price.insert(std::make_pair("book1",30));
    price.insert(std::make_pair("book2",60));
    for (auto elem: price)
        cout << elem.first <<endl;


    std::vector <std::pair<string, int>> table;
    table.push_back(std::make_pair("C++Primer",650)) ;
    table.push_back(std::make_pair("HarryPotter",30));
    for (auto elem: table)
        cout << elem.first <<endl;
    ///////////////////////////////////////////////////////////////
    studentMap[1] = "Tom";
    studentMap[3] = "Jack";
    studentMap[6] = "John";
}
