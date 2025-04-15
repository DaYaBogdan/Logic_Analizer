#ifndef OBJECT
#define OBJECT

#include <windows.h>

class Object
{
public:
	Object() : x(0), y(0) {};

	Object(short _x, short _y) : x(_x), y(_y){};

	~Object() {};

	int GoToXY() 
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsole, { x, y });
		return 0;
	};

private:
	short x;
	short y;
};

#endif // !OBJECT