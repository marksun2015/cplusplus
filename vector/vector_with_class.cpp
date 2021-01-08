#include <string>
#include <vector>

using namespace std;

class chapter {          //被包的那個不知道該怎麼找到他的值
    public:
        string  chap_name;
        int     paragraph;
        int     pages;
};

class book {             //book可能會有幾萬筆資料。
    public:
        string  name;
        int     all_pages;
        chapter ch;
};

int main() {
    vector <book> book_table;
    book temp;

    temp.name = "Hello";
    temp.all_pages = 10;

    temp.ch.chap_name = "ch1";
    temp.ch.pages = 2;
    temp.ch.paragraph = 5;

    book_table.push_back(temp);
}
