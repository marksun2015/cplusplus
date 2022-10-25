#include <string>
#include <vector>

using namespace std;

class Chapter {          //被包的那個不知道該怎麼找到他的值
    public:
        string  chap_name;
        int     paragraph;
        int     pages;
};

class Book {             //book可能會有幾萬筆資料。
    public:
        string  name;
        int     all_pages;
        Chapter ch;
};

int main() {
    vector <Book> book_table;
    Book temp;

    temp.name = "Hello";
    temp.all_pages = 10;

    temp.ch.chap_name = "ch1";
    temp.ch.pages = 2;
    temp.ch.paragraph = 5;

    book_table.push_back(temp);
}
