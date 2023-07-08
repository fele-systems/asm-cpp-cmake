#include <cstdint>
#include <iostream>
#include <iomanip>
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

#define dbg(what) std::cout << #what << ": " << what << std::endl;
#define dbg_hl(hl) std::cout << #hl << "[] = { 0x" << std::hex << hl[0] \
    << ", 0x" << std::hex << hl[1] << "}" << std::dec << std::endl

int main() {
    bool carry = false;
    uint32_t num0[2] = { 0xFFFFFFFF, 0 };
    dbg_hl(num0);
    uint32_t num1[2] = { 1, 0 };
    dbg_hl(num1);
    uint32_t num2[2] = { 0, 0 };

    num2[0] = adc32(num0[0], num1[0], &carry);
    num2[1] = num0[1] + num1[1] + carry;
    dbg_hl(num2);
    uint64_t result = static_cast<uint64_t>(num2[0]) | (static_cast<uint64_t>(num2[1]) << 32);
    uint64_t unsafe_result = *reinterpret_cast<uint64_t*>(num2);
    dbg(result);
    dbg(unsafe_result);
    return 0;
}
