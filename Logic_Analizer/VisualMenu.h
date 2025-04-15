#ifndef VISUALMENU
#define VISUALMENU

#include "Button.h"
#include <list>
#include <map>
#include <conio.h>

#define EXIT_KEY 27
#define LIST_NEXT_KEY 80
#define LIST_LAST_KEY 72
#define EXECUTE_KEY 13

template <class in = int&, class out = int> class VisualMenu
{
public:

	VisualMenu();
	VisualMenu(in obj);
	~VisualMenu();

	out openMenu();

	int setInObject(in obj);
	out getOutObject();

	int addElement(Label obj);
	int addElement(Button <in, out> obj);

private:

	int print();

	int hideCursor();
	int moveCursor();

	int execute();

	int cursor;
	bool isOpened;

	in inObject;
	out outObject;

	std::list <Label> labels;
	std::list <Button <in, out>> buttons;
};

#include "VisualMenu_impl.h"

#endif