#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <cstdlib>

#define DEBUG 0

class Base {
    public:
        virtual ~Base();

};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif