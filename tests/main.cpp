#include <iostream>

#include "Golden_rc4.h"
#include "Test_rc4.h"


static_assert(sizeof(size_t) == 8, "size_t expected to be 64 bit");


template <typename T1, typename T2, typename T3> void run_test(const T1 &key, const T2 &data, T3 count)
{
    Golden_rc4 grc4 { key };
    auto grc4_enc = grc4.run(data);

    Test_rc4 trc4 { key };
    auto trc4_enc = trc4.run(data);

    if (grc4_enc == data)
    {
        std::cout << "run_test count = " << count << std::endl;
        throw std::logic_error("grc4_enc == data");
    }

    if (trc4_enc == data)
    {
        std::cout << "run_test count = " << count << std::endl;
        throw std::logic_error("trc4_enc == data");
    }

    if (grc4_enc != trc4_enc)
    {
        std::cout << "run_test count = " << count << std::endl;
        throw std::logic_error("grc4_enc != trc4_enc");
    }
}


int main(int argc, char *argv[])
try
{
    argc = argc;
    argv = argv;

    {
        std::vector<uint8_t> key { 0 };
        std::vector<uint8_t> data { 0 };

        auto count { 0 };

        while (count < 1000)
        {
            run_test(key, data, count);
            data.push_back(0);
            ++count;
        }
    }

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
