#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    // str append
    string str1 = "abc";
    string str2 = "efg";
    string str3 = "hij";
    string str4;
    str1.append(str2);
    str4 = str2 + str3; 
    std::cout << str1 << std::endl;
    std::cout << str4 << std::endl;

    // str to char
    string str = "";
    cout<<"Enter the string:\n";
    cin>>str;

    char arr[str.length() + 1];
    strcpy(arr, str.c_str());
    cout<<"String to char array conversion:\n";
    for (int i = 0; i < str.length(); i++)
        cout << arr[i];
}
