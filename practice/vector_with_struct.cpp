#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

typedef struct Appointments {
  std::string start_str;
  std::string stop_str;
  int start_time;
  int stop_time;
}APP;

int main() {
    std::vector<Appointments> app;

    APP apt;
    apt.start_str = "10:00";
    apt.stop_str = "12:00";
    apt.start_time = 1000;
    apt.stop_time = 2000;

    app.push_back(apt);
    app.push_back({"9:30","16:00",930,1600});
    app.push_back({"9:10","15:00",910,1500});

    for(auto a: app)
        std::cout << a.start_str << std::endl;
}
