#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    /* int to str */
    stringstream ss1;
    int number  = 123456;
    ss1 << number; //把int型態變數寫入到stringstream

    cout << "int to string" <<endl;
    string convert_str;
    ss1 >>  convert_str;  //透過串流運算子寫到string類別即可

    cout << "number:" << number <<endl;
    cout << "convert to str type:" << convert_str <<endl;
    cout << "string to int" <<endl;

    /* str to in */
    stringstream ss2;
    //std::stoi(str)
    string numberStr = "654321";
    cout << "str type:" << numberStr <<endl;
    int num;
    ss2 << numberStr; 
    ss2 >> num;
    cout << "convert to num:" << num <<endl;

}
