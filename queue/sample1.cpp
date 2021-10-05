#include <iostream>
#include <string>
#include <queue>
#include <stack>

#include <vector>

using namespace std;

void tokenize(std::string const &str, const char delim,
        std::vector<std::string> &out)
{
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

 
int main()
{
    queue<string> q;
    //std::string delimiter = " ";
    
    const char delim = ' ';
    
 
    cout << "Pushing command\n";
    q.push("SetGeometry 123 0 0 800 600");
    q.push("SetToobar 123 0");
    q.push("command3");
    q.push("command4");

    cout << "Now, retrieve those values in FIFO order.\n";
    while(!q.empty()) {
        cout << "===================Popping================== " << "\n";
        cout << q.front() << "\n";
        cout << "-------------------------------------------- " << "\n";
        
        std::string s = q.front();
        std::vector<std::string> out;
        //cout << "s " << s << "\n";
        tokenize(s, delim, out);
        for (auto &s: out) {
            std::cout << s << std::endl;
        }

        q.pop();
    }
    cout << endl;

    return 0;
}
