#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 重写排序方法
// 常引用const T &xxx
bool comp(const int &a, const int &b)
{
    printf("[a < b][%d < %d] : %d\n", a, b , a<b);
    return a < b;
}

int main()
{
    vector<int> v = {2, 3, 1, 6, 2, 5, 4};
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
