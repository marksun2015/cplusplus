#include <string>
#include <vector>
#include <memory>
#include <iostream>

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
    vector <unique_ptr<Book>> book_table;
 
    unique_ptr <Book> book1 = make_unique <Book>() ;
    book1->name = "HarryPoter";
    book1->all_pages = 10;
    book1->ch.chap_name = "ch1";
    book1->ch.pages = 2;
    book1->ch.paragraph = 5;
    book_table.push_back(std::move(book1));

    unique_ptr <Book> book2 = make_unique <Book>() ;
    book2->name = "WarI";
    book2->all_pages = 20;
    book2->ch.chap_name = "ch1";
    book2->ch.pages = 3;
    book2->ch.paragraph = 4;
    book_table.push_back(std::move(book2));
    
    for (auto &elem : book_table) {
        cout <<"name: " << elem->name << endl;
        cout <<"pages: " << elem->all_pages << endl;
        cout <<"chap name: " << elem->ch.chap_name << endl;
        cout << endl;

    }

#if 0
    Book temp;

    temp.name = "Hello";
    temp.all_pages = 10;

    temp.ch.chap_name = "ch1";
    temp.ch.pages = 2;
    temp.ch.paragraph = 5;

    book_table.push_back(temp);
#endif
}
