// abstract-factory.hpp
#include <memory>
#include <iostream>

template <typename P>
struct AbstractFactory {
	virtual std::unique_ptr<P> create(void) = 0;
};

template <typename F, typename P>
struct Factory : AbstractFactory<P> { // Apply CRTP
	virtual ~Factory() = default;

	struct Product : P { // Couple factory and product
		virtual ~Product() = default;
	};

	std::unique_ptr<P> create(void) override {
		return std::make_unique<typename F::Product>(); // Generate concrete product
	};
};

