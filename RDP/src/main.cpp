#include "iostream"
#include "Ring.hpp"


int main() {
    size_t ss = 5;
    Ring ring(ss);

    for (int i = 0; i < ss; ++i) {
        ring.Add(i + 1);
    }
    ring.Add(6);
    ring.Add(6);
    ring.Check();
    int temp = -1;
    std::cout << ring.Take(temp); std::cout << " val = " << temp << std::endl;
    std::cout << ring.Take(temp); std::cout << " val = " << temp << std::endl;
    ring.Check();
    ring.Add(7);
    ring.Check();
    std::cout << ring.Take(temp); std::cout << " val = " << temp << std::endl;
    std::cout << ring.Take(temp); std::cout << " val = " << temp << std::endl;
    ring.Check();
    std::cout << ring.Take(temp); std::cout << " val = " << temp << std::endl;
    std::cout << ring.Take(temp); std::cout << " val = " << temp << std::endl;
    std::cout << ring.Take(temp); std::cout << " val = " << temp << std::endl;
    std::cout << ring.Take(temp); std::cout << " val = " << temp << std::endl;
    ring.Check();

    return 0;
}