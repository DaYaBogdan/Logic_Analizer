#ifndef LABEL
#define LABEL
#include "Object.h"

#include <iostream>

class Label :
    protected Object
{
public:
	Label() : Object(), name("default") {};

	Label(short _x, short _y, std::string _name) : Object(_x, _y), name(_name) {};

	~Label() {};

	int print()
	{
		GoToXY();
		std::cout << name;
		return 0;
	}

private:
    std::string name;
};

#endif