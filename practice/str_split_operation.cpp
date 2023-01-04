#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

//istream& getline(istream& is, string& str);
//istream& getline(istream& is, string& str, char delimiter);
const std::vector<std::string> split(const std::string &str, const char &delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string tok;

    while (std::getline(ss, tok, delimiter)) {
        result.push_back(tok);
    }
    return result;
}

int main() {
    std::string str = "This is a c++ string";
#if 1
    std::vector<std::string> ret = split(str, ' ');
    for (auto& s : ret) {
        cout << s << "\n";
    }
#else
    std::stringstream ss(str);
    std::string tok;
    while(getline(ss, tok, ' ')) {
        cout  << tok <<std::endl;
    }
#endif
    
    std::string str2 = "This0is0a0c++0string";
    int pos = str2.find('s');
    std::cout << "pos: " << pos << std::endl;
    str2.erase(0, pos);
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "sub str2(0~5): " << str2.substr(0, 5) << std::endl;

    return 0;
}

