#include <cstdint>
#include <iostream>
#include <vector>

extern "C" {
	uint32_t add32(uint32_t,uint32_t);

    void settrue(bool*);

    uint32_t adc32(uint32_t,uint32_t,bool*);

    bool add64_check_carry(uint64_t,uint64_t,uint64_t*);

    uint32_t fl_str_len(const char* src);

    int32_t fl_str_toupper(const char* src, uint32_t n, char* dst);

    void from_cpp() {
        std::cout << "Calling C++ from Assembly!" << std::endl;
    }
}

bool add_check_carry(uint64_t x, uint64_t y, uint64_t& out)
{
    return add64_check_carry(x, y, &out);
}

int main() {
	auto sum = add32(256, 100);

    const char* mystr = "Hello, world";
    auto l = fl_str_len(mystr);
    std::cout << "Len of '" << mystr << "' is: " << l << std::endl;

    std::vector<char> buffer(l+1, '\0');
    auto r = fl_str_toupper(mystr, l, buffer.data());
    std::cout << "Uppercase: " << std::string{ buffer.data(), r } << " ... Result: " << r << std::endl;

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
