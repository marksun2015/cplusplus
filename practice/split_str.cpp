#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

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
    std::vector<std::string> ret = split(str, ' ');

    for (auto& s : ret) {
        cout << s << "\n";
    }
    return 0;
}

