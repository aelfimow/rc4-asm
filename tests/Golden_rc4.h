#ifdef GOLDEN_RC4_H
#error Already included
#else
#define GOLDEN_RC4_H

#include <cstdint>
#include <vector>

class Golden_rc4
{
    public:
        explicit Golden_rc4(const std::vector<uint8_t> &key);
        ~Golden_rc4();

        std::vector<uint8_t> run(const std::vector<uint8_t> &data);

    private:
        std::vector<uint8_t> sbox;

    public:
        Golden_rc4() = delete;
        Golden_rc4(const Golden_rc4 &instance) = delete;
        Golden_rc4(const Golden_rc4 &&instance) = delete;
        Golden_rc4 &operator=(const Golden_rc4 &instance) = delete;
        Golden_rc4 &operator=(const Golden_rc4 &&instance) = delete;
};

#endif
