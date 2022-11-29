#include <algorithm>
#include <iostream>
#include <cstring>
#include <memory>
#include <gmock/gmock.h>
#include <sstream>

using namespace std;

///////////////////////////////////////
class Tool {
    public:
        virtual ~Tool() = default;
        virtual void write(int index) = 0;
};

///////////////////////////////////////
class ToolPencil : public Tool {
    public:
         explicit ToolPencil();

    public:
        void write(int index) override;
};

ToolPencil::ToolPencil(){}

void ToolPencil::write(int index) {
    std::cout << "pencil: " << index << std::endl;
}

///////////////////////////////////////
class ToolPen : public Tool {
    public:
        explicit ToolPen();

    public:
        void write(int index) override;
};

ToolPen::ToolPen(){}

void ToolPen::write(int index) {
    std::cout << "pen: " << index << std::endl;
}

///////////////////////////////////////
class Box {
    public:
        explicit Box(std::unique_ptr <Tool> pen);
        ~Box();

    public:
        void show();

    private:
        unique_ptr <Tool> tool_pen_; 
};

Box::Box(std::unique_ptr <Tool> pen):tool_pen_(std::move(pen)){
    //tool_pen = std::move(pen);
}

Box::~Box(){}

void Box::show(){
    std::cout << "show ";    
    tool_pen_->write(2);
}

void solve(std::istream &is, std::ostream &os) {
    /*
    std::string input;
    getline(is, input);
   
    std::stringstream ss(input);
    int output;
    while(ss >> output) {
        std::cout << output << std::endl;
    }
    */

    //unique_ptr <ToolPen> pen = make_unique <ToolPen> ();
    //unique_ptr <Box> box = make_unique <Box> (std::move(pen));
    
    unique_ptr <ToolPencil> pencil = make_unique <ToolPencil> ();
    unique_ptr <Box> box = make_unique <Box> (std::move(pencil));
    box->show();
    
}

int main(int argc, char* argv[])
{

#if 1
    solve(std::cin, std::cout);
#else
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
#endif

    return 0;
}
