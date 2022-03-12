#include <iostream>
#include "serialize.hpp"

void    test(Data *structToTest) {
    std::cout << "Addr base :\t\t\t" << structToTest << std::endl
        << "serialize ret :\t\t\t" << serialize(structToTest) << std::endl
        << "deserialize of serialize ret :\t" << deserialize(serialize(structToTest)) << std::endl;
    std::cout << "Are they the same :\t\t";
    if (deserialize(serialize(structToTest)) == structToTest)
        std::cout << "Whaoow ! [wink]" << std::endl;
    else
        std::cout << "Fail !" << std::endl;
}

int main() {
    Data    base = {1, 'c'};
    Data    *cpyPtr = &base;
    Data    *nullPtr = NULL;

    test(&base);
    std::cout << std::endl;
    test(cpyPtr);
    std::cout << std::endl;
    test(nullPtr);



    return 0;
}