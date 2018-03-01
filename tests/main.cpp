#include <iostream>

#include "Golden_rc4.h"
#include "Test_rc4.h"


static_assert(sizeof(size_t) == 8, "size_t expected to be 64 bit");

static void test0()
{
    const std::string func_name { __func__ };

    std::cout << func_name << ": started" << std::endl;

    constexpr auto keySize { 100 };
    constexpr auto dataSize { 1000 };

    std::vector<uint8_t> key { 0 };

    while (key.size() < keySize)
    {
        std::vector<uint8_t> data { 0 };

        while (data.size() < dataSize)
        {
            Golden_rc4 grc4_a { key };
            Golden_rc4 grc4_b { key };

            auto grc4_enc = grc4_a.run(data);

            auto grc4_dec = grc4_b.run(grc4_enc);

            if (grc4_enc == data)
            {
                throw std::logic_error(func_name + ": grc4_enc == data");
            }

            if (grc4_enc == grc4_dec)
            {
                throw std::logic_error(func_name + ": grc4_enc == grc4_dec");
            }

            if (data != grc4_dec)
            {
                throw std::logic_error(func_name + ": data != grc4_dec");
            }

            data.push_back(0);
        }

        key.push_back(0);
    }
}

static void test1()
{
    const std::string func_name { __func__ };

    std::cout << func_name << ": started" << std::endl;

    constexpr auto keySize { 100 };
    constexpr auto dataSize { 1000 };

    std::vector<uint8_t> key { 0 };

    while (key.size() < keySize)
    {
        std::vector<uint8_t> data { 0 };

        while (data.size() < dataSize)
        {
            Golden_rc4 grc4 { key };
            auto grc4_enc = grc4.run(data);

            Test_rc4 trc4 { key };
            auto trc4_enc = trc4.run(data);

            if (grc4_enc == data)
            {
                throw std::logic_error(func_name + ": grc4_enc == data");
            }

            if (trc4_enc == data)
            {
                throw std::logic_error(func_name + ": trc4_enc == data");
            }

            if (grc4_enc != trc4_enc)
            {
                throw std::logic_error(func_name + ": grc4_enc != trc4_enc");
            }

            data.push_back(0);
        }

        key.push_back(0);
    }
}

static void test2()
{
    const std::string func_name { __func__ };

    std::cout << func_name << ": started" << std::endl;

    constexpr auto keySize { 100 };
    constexpr auto dataSize { 1000 };

    uint8_t keyValue { 255 };
    uint8_t dataValue { 0 };

    std::vector<uint8_t> key;
    key.push_back(keyValue);

    while (key.size() < keySize)
    {
        std::vector<uint8_t> data { 0 };

        while (data.size() < dataSize)
        {
            Golden_rc4 grc4 { key };
            auto grc4_enc = grc4.run(data);

            Test_rc4 trc4 { key };
            auto trc4_enc = trc4.run(data);

            if (grc4_enc == data)
            {
                throw std::logic_error(func_name + ": grc4_enc == data");
            }

            if (trc4_enc == data)
            {
                throw std::logic_error(func_name + ": trc4_enc == data");
            }

            if (grc4_enc != trc4_enc)
            {
                throw std::logic_error(func_name + ": grc4_enc != trc4_enc");
            }

            ++dataValue;
            data.push_back(dataValue);
        }

        --keyValue;
        key.push_back(keyValue);
    }
}

int main(int argc, char *argv[])
try
{
    argc = argc;
    argv = argv;

    test0();
    test1();
    test2();

    return EXIT_SUCCESS;
}
catch (std::exception &exc)
{
    std::cerr << "Exception: " << exc.what() << std::endl;
    return EXIT_FAILURE;
}
catch (...)
{
    std::cerr << "Error: unknown exception" << std::endl;
    return EXIT_FAILURE;
}
