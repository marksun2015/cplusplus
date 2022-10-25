#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    std::map <string, int> mp_price;
    std::vector <pair<string, int>> book_table;

    mp_price.insert({"HarryPoter", 500});
    mp_price.insert({"WebWorld", 400});
    mp_price.insert({"DuckLife", 300});

    book_table = {mp_price.begin(), mp_price.end()};

    sort(book_table.begin(), book_table.end(),
            [](auto x, auto y){
                return x.second < y.second;
              });

    for(auto bt : book_table)
        std::cout << bt.first << " " << bt.second << std::endl;
}
