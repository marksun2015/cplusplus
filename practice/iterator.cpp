#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    vector<int> a;    //建構整數向量a
    vector<int>::iterator h;   //宣告一整數向量迭代器h

    for(int i = 0; i < 10; i++){
        a.push_back(i);
    }

    for(h = a.begin(); h != a.end(); h++) {
        cout << *h;
    }    
    //顯示0123456789

    cout << endl << *(h-1);     //顯示9
    cout << endl << *(h-2);     //顯示8
    cout << endl << *(h-3);     //顯示7
}
