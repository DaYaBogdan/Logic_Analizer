#ifndef FUNCTION
#define FUNCTION

template <class in = int&, class out = int>
class Function
{
public:

	using Func = out(*) (in);

	Function(Func _func) : func(_func) {};
	~Function() {};

	out callFunction(in obj) const { return func(obj); };

private:
	Func func;
};

#endif // !FUNCTION

