#ifdef TEST_RC4_H
#error Already included
#else
#define TEST_RC4_H

#include <cstdint>
#include <vector>

class Test_rc4
{
    public:
        explicit Test_rc4(const std::vector<uint8_t> &key);
        ~Test_rc4();

        std::vector<uint8_t> run(const std::vector<uint8_t> &data);

    private:
        std::vector<uint8_t> sbox;

    public:
        Test_rc4() = delete;
        Test_rc4(const Test_rc4 &instance) = delete;
        Test_rc4(const Test_rc4 &&instance) = delete;
        Test_rc4 &operator=(const Test_rc4 &instance) = delete;
        Test_rc4 &operator=(const Test_rc4 &&instance) = delete;
};

#endif
