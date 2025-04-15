#ifndef BUTTON
#define BUTTON

#include "Label.h"
#include "Function.h"

template <class in = int&, class out = int>
class Button :
	public Label,
	public Function<in, out>
{
public:

	Button(Function<in, out> _func) : Function<in, out>(_func) {};
	Button(short _x, short _y, std::string _name, Function<in, out> _func) : Label(_x, _y, _name), Function<in, out>(_func) {};

};

#endif // !BUTTON
