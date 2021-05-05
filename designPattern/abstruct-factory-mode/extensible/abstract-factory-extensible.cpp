#include "abstract-factory-extensible.hpp"

// Product
struct Button {
	virtual ~Button() = default;
	virtual void draw(void) {}; 
};

// Factory #1
struct LinuxFactory : Factory<LinuxFactory, Button> {
	struct Product : Button {
		virtual ~Product() = default;

		void draw(void) override { std::cout << "Linux button" << std::endl; }
	};
};

// Factory #2
struct MacOSFactory final : Factory<MacOSFactory, Button> {
	struct Product : Button {
		virtual ~Product() = default;

		void draw(void) override { std::cout << "MacOS button" << std::endl; }
	};
};

int main() {
	std::unique_ptr<AbstractFactory<Button>> factory;
	std::unique_ptr<Button> button;
	
	factory = std::make_unique<LinuxFactory>();
	button = factory->create();
	button->draw();

	factory = std::make_unique<MacOSFactory>();
	button = factory->create();
	button->draw();

	return 0;
}

