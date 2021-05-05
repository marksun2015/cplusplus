#include <memory>
#include <iostream>

// Product
struct Button {
	virtual ~Button() = default;
	virtual void draw(void) = 0; 
};

struct LinuxButton final : Button {
	void draw(void) override { std::cout << "Linux button" << std::endl; }
};

struct MacOSButton final : Button {
	void draw(void) override { std::cout << "MacOS button" << std::endl; }
};

// Factory
struct ButtonFactory {
	virtual ~ButtonFactory() = default;
	virtual std::unique_ptr<Button> create(void) = 0;
};

struct LinuxFactory final : ButtonFactory {
	virtual ~LinuxFactory() = default;

	std::unique_ptr<Button> create(void) override
	{
		return std::make_unique<LinuxButton>();
	}
};

struct MacOSFactory final : ButtonFactory {
	virtual ~MacOSFactory() = default;

	std::unique_ptr<Button> create(void) override
	{
		return std::make_unique<MacOSButton>();
	}
};

int main() {
	std::unique_ptr<ButtonFactory> factory;
	std::unique_ptr<Button> button;
	
	factory = std::make_unique<LinuxFactory>();
	button = factory->create();
	button->draw();

	factory = std::make_unique<MacOSFactory>();
	button = factory->create();
	button->draw();

	return 0;
}

