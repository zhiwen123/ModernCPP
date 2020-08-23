// ModernCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CRTP.H"

int main()
{
    // Use base interface
    Derived derived;
    derived.baseInterface();

    // Compile time polymorphism
    Base<Derived>& base = derived;
    base.doSomething();

    // Console Ouput: 
    // Do something from derived class
    // Base class also provides extra interfaces to the derived class.
}