#include <iostream>
#include <memory>
#include <string>

using namespace std;

/* Abstract definitions */
class GUIComponent {
    public:
        virtual ~GUIComponent() = default;
        virtual void draw() const = 0;
};

class Frame  : public GUIComponent {};
class Button : public GUIComponent {};
class Label  : public GUIComponent {};

class GUIFactory {
    public:
        virtual ~GUIFactory() = default;
        virtual std::unique_ptr<Frame> createFrame() = 0;
        virtual std::unique_ptr<Button> createButton() = 0;
        virtual std::unique_ptr<Label> createLabel() = 0;
        static std::unique_ptr<GUIFactory> create(const std::string& type);
};

/* Windows support */
class WindowsFactory : public GUIFactory {
    private:
        class WindowsFrame : public Frame {
            public:
                void draw() const override { std::cout << "I'm a Windows-like frame" << std::endl; }
        };
        class WindowsButton : public Button {
            public:
                void draw() const override { std::cout << "I'm a Windows-like button" << std::endl; }
        };
        class WindowsLabel : public Label {
            public:
                void draw() const override { std::cout << "I'm a Windows-like label" << std::endl; }
        };
    public:
        std::unique_ptr<Frame> createFrame() override { return std::make_unique<WindowsFrame>(); }
        std::unique_ptr<Button> createButton() override { return std::make_unique<WindowsButton>(); }
        std::unique_ptr<Label> createLabel() override { return std::make_unique<WindowsLabel>(); }
};

/* Linux support */
class LinuxFactory : public GUIFactory {
    private:
        class LinuxFrame : public Frame {
            public:
                void draw() const override { std::cout << "I'm a Linux-like frame" << std::endl; }
        };
        class LinuxButton : public Button {
            public:
                void draw() const override { std::cout << "I'm a Linux-like button" << std::endl; }
        };
        class LinuxLabel : public Label {
            public:
                void draw() const override { std::cout << "I'm a Linux-like label" << std::endl; }
        };
    public:
        std::unique_ptr<Frame> createFrame() override { return std::make_unique<LinuxFrame>(); }
        std::unique_ptr<Button> createButton() override { return std::make_unique<LinuxButton>(); }
        std::unique_ptr<Label> createLabel() override { return std::make_unique<LinuxLabel>(); }
};

std::unique_ptr<GUIFactory> GUIFactory::create(const string& type) {
    std::cout << "GUIFactory create...";

    if (type == "windows") 
        return std::make_unique<WindowsFactory>();
    return std::make_unique<LinuxFactory>();
}

/* User code */
void buildInterface(GUIFactory& factory) {
    auto frame = factory.createFrame();
    auto button = factory.createButton();
    auto label = factory.createLabel();

    frame->draw();
    button->draw();
    label->draw();
}

int main(int argc, char *argv[]) {
    if (argc < 2) 
        return 1;

    auto guiFactory = GUIFactory::create(argv[1]);
    buildInterface(*guiFactory);
}
