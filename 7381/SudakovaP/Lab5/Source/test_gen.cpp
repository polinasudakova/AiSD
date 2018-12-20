
#include <iostream>
#include <cstdlib>

int main(int argc, char const *argv[])
{
    std::cout << 0 << std::endl;
    for (int i = 0; i < atoi(argv[1]); ++i)
        std::cout << i << ' ';
    return 0;
} 