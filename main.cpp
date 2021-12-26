#include <iostream>

extern "C" {
	uint32_t add32(uint32_t,uint32_t);

    void settrue(bool*);

    uint32_t adc32(uint32_t,uint32_t,bool*);
}

int main() {
	auto sum = add32(256, 100);

	std::cout << sum << std::endl;

    bool b = false;
    std::cout << "Before settrue: " << b << std::endl;
    settrue(&b);
    std::cout << "After settrue: " << b << std::endl;

    bool carry = false;
    auto s = adc32(0xFFFFFFFF, 100, &carry);
    if (carry)
    {
        std::cout << "Has carry" << std::endl;
    }
    std::cout << "Result: " << s << std::endl;
	return 0;
}
