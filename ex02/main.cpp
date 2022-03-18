#include <iostream>
#include "Base.hpp"

int main() {
    std::srand(time(NULL));

    std::cout << "------- Basic ---------" << std::endl;
    Base*   val = generate();
    Base&   ref = *val;
    Base*   nullPtr = NULL;
    identify(val);
    identify(ref);
    std::cout << "NULL ptr identify : ";
    identify(nullPtr);
    std::cout << std::endl;
    delete val;

    std::cout << "--------- Loop ----------" << std::endl;
    for(int i = 0; i < 10; i++)
    {
        Base*   base = generate();
        std::cout << "Identify with pointer : ";
        identify(base);
        std::cout << "Identify with reference : ";
        identify(*base);
        delete base;
        std::cout << std::endl;
    }
    return 0;   
}