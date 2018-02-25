#include <iostream>

#include "Golden_rc4.h"


static_assert(sizeof(size_t) == 8, "size_t expected to be 64 bit");


template <typename T> void check_size(const T &v1, const T &v2)
{
    bool isEqual { v1.size() == v2.size() };

    if (!isEqual)
    {
        throw std::logic_error("size check failed");
    }
}

int main(int argc, char *argv[])
try
{
    argc = argc;
    argv = argv;

    std::vector<uint8_t> key { 1, 2, 3, 4, 5 };
    Golden_rc4 grc4 { key };

    const std::vector<uint8_t> data { 0, 0, 0, 0 };
    auto result = grc4.run(data);
    check_size(data, result);

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
