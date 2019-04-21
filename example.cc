#include <iostream>

#include <variant>
#include <vector>
#include <string>
#include "typeswitch.hh"

template<typename T>
void print(T &&sum_type)
{
	typeswitch (std::forward<T>(sum_type)) {
		typecase (std::string, str)
			std::cout << str << '\n';
		
		typecase (int, i)
			std::cout << i << '\n';
		
		typecase (std::vector<int>, vec) {
			for (auto x : vec)
				std::cout << x << ' ';
			std::cout << '\n';
		}
	}
}

template<typename T>
void test()
{
	std::puts(__PRETTY_FUNCTION__);
	T value = std::string("hello, world");
	for (unsigned i = 0; i < 3; ++i) {
		switch (i) {
			case 1: value = std::vector<int> { 10, 20, 30, 40, 50 }; break;
			case 2: value = 3; break;
			default:
				;
		}

		print(value);
	}
}

int main()
{
	test<std::variant<std::string, std::vector<int>, int>>();
	std::putchar('\n');
	test<std::any>();
}
