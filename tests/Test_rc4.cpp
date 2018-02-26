#include <rc4func.h>

#include "Test_rc4.h"


Test_rc4::Test_rc4(const std::vector<uint8_t> &key) :
    sbox { }
{
    sbox.reserve(256);
    rc4init(key.data(), key.size(), sbox.data());
}

Test_rc4::~Test_rc4()
{
}

std::vector<uint8_t> Test_rc4::run(const std::vector<uint8_t> &data)
{
    std::vector<uint8_t> result(data.size());

    rc4run(data.data(), data.size(), result.data(), sbox.data());

    return result;
}
