#include "Golden_rc4.h"


Golden_rc4::Golden_rc4(const std::vector<uint8_t> &key) :
    sbox { }
{
    constexpr size_t maxCount { 256 };

    for (size_t i = 0; i < maxCount; ++i)
    {
        const uint8_t value { static_cast<uint8_t>(i) };
        sbox.push_back(value);
    }

    size_t j { 0 };

    for (size_t i = 0; i < maxCount; ++i)
    {
        j += sbox[i] + key[i % key.size()];
        j %= sbox.size();

        std::swap(sbox[i], sbox[j]);
    }
}

Golden_rc4::~Golden_rc4()
{
}

std::vector<uint8_t> Golden_rc4::run(const std::vector<uint8_t> &data)
{
    std::vector<uint8_t> result;

    size_t i { 0 };
    size_t j { 0 };

    const size_t sboxSize { sbox.size() };

    for (auto &d: data)
    {
        ++i;
        i %= sboxSize;

        j += sbox[i];
        j %= sboxSize;

        std::swap(sbox[i], sbox[j]);

        const size_t a { sbox[i] };
        const size_t b { sbox[j] };
        size_t sum { a + b };
        sum %= sboxSize;

        const auto rnum { sbox[sum] };

        const auto value { rnum ^ d };

        result.push_back(value);
    }

    return result;
}
