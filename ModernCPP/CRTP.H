#pragma once

#include <iostream>

// Code example is from: https://www.fluentcpp.com/2017/05/12/curiously-recurring-template-pattern/
// The key benefit of CRTP is to realize compile time polymorphism which is performance improvement
// compared with runtime polygmorphism. 

template <typename T>
class Base
{
public:
	// Notice here virtual keyword is not needed.
	void doSomething()
	{
		T& derived = static_cast<T&>(*this);
		derived.doSomething(); // Note here compiler will check if derived class T has interface of doSomething.
	}

	void baseInterface()
	{
		std::cout << "Base class also provides extra interfaces to the derived class." << std::endl;
	}

private:
	// The private-constructor-and-template-friend trick to to avoid derived classes
	// to inherit from the same base class.
	Base() {};
	friend T;
};

class Derived : public Base<Derived> 
{
public:
	void doSomething()
	{
		std::cout << "Do something from derived class" << std::endl;
	}
};

