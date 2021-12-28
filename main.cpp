#include <cstdint>
#include <iostream>

extern "C" {
	uint32_t add32(uint32_t,uint32_t);

    void settrue(bool*);

    uint32_t adc32(uint32_t,uint32_t,bool*);


    bool add64_check_carry(uint64_t,uint64_t,uint64_t*);
}

bool add_check_carry(uint64_t x, uint64_t y, uint64_t& out)
{
    return add64_check_carry(x, y, &out);
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


    uint64_t result;

    if (add_check_carry( UINT64_MAX, 1, result) )
    {
        std::cout << "had carry" << std::endl;
    }

    return 0;
}
