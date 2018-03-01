#include <iostream>

#include "Golden_rc4.h"
#include "Test_rc4.h"


static_assert(sizeof(size_t) == 8, "size_t expected to be 64 bit");


static void test1()
{
    const std::string func_name { __func__ };

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


int main(int argc, char *argv[])
try
{
    argc = argc;
    argv = argv;

    test1();

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
