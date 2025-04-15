#ifndef VISUALMENU_IMPL
#define VISUALMENU_IMPL

#include "VisualMenu.h"

template <class in, class out>
out VisualMenu<in, out>::openMenu() 
{ 
	isOpened = true; 
	hideCursor();

	while (isOpened)
	{
		system("cls");
		print();
		moveCursor();
	}

	system("cls");

	return outObject;
};

template <class in, class out>
int VisualMenu<in, out>::setInObject(in obj) { inObject = obj; return 0; };

template <class in, class out>
out VisualMenu<in, out>::getOutObject() { return outObject; };

template <class in, class out>
int VisualMenu<in, out>::addElement(Label obj)
{
	labels.push_back(obj);
	return 0;
};

template <class in, class out>
int VisualMenu<in, out>::addElement(Button <in, out> obj)
{
	buttons.push_back(obj);
	return 0;
};

template <class in, class out>
int VisualMenu<in, out>::print()
{
	int i = 0;
	HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);

	for (Label& elem : labels)
		elem.print();

	for (Button<in, out>& elem : buttons)
	{
		SetConsoleTextAttribute(handler, 8);
		if (i == cursor)
			SetConsoleTextAttribute(handler, 15);
		elem.print();
		i++;
	}

	SetConsoleTextAttribute(handler, 15);
	return 0;
};

template <class in, class out>
int VisualMenu<in, out>::hideCursor()
{
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	return 0;
};

template <class in, class out>
int VisualMenu<in, out>::moveCursor()
{
	int i = (int)_getch();

	switch (i)
	{
	case EXIT_KEY:
		isOpened = false;
		break;
	case LIST_NEXT_KEY:
		++cursor;
		if (cursor >= buttons.size()) cursor = 0;
		break;
	case LIST_LAST_KEY:
		--cursor;
		if (cursor < 0) cursor = buttons.size() - 1;
		break;
	case EXECUTE_KEY:
		execute();
		break;
	case 0 || 0xE0:
		moveCursor();
		break;
	}

	return 0;
};

template <class in, class out>
int VisualMenu<in, out>::execute()
{
	for (Button<in, out>& elem : buttons)
	{
		if (!cursor)
		{
			system("cls");
			outObject = elem.callFunction(inObject);
			break;
		}
		--cursor;
	}
	return 0;
};

template <class in, class out>
VisualMenu<in, out>::VisualMenu() : cursor(0) {}

template <class in, class out>
VisualMenu<in, out>::VisualMenu(in obj) : inObject(obj) {};

template <class in, class out>
VisualMenu<in, out>::~VisualMenu() {}

#endif