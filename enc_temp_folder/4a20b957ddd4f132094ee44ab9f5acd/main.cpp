#include "LogicAnalizer.h"
#include "VisualMenu.h"
#include "iostream"

int inputLogic(std::string&);
int showLogic(std::string&);
int cutLogic(std::string&);

int main()
{
	std::string logic;
	VisualMenu <std::string&, int> menu { logic };

	menu.addElement({ 4, 4, "Input Logic", inputLogic });
	menu.addElement({ 4, 5, "Show Logic", showLogic });
	menu.addElement({ 4, 6, "Cut Logic", cutLogic });

	menu.openMenu();
}

int inputLogic(std::string& logic)
{
	std::cin >> logic;
	return 0;
}

int showLogic(std::string& logic)
{
	LogicAnalizer analizer;

	if(analizer.analisis(logic))
		for (const auto& elem : analizer.returnErrors())
			std::cout << "ERROR ON INDEX: " << elem << std::endl;

	std::cout << analizer.returnTransformedLogic() << std::endl;

	_getch();

	return 0;
}

int cutLogic(std::string& logic)
{
	LogicAnalizer analizer;

	analizer.cut(logic);

	std::cout << analizer.returnTransformedLogic() << std::endl;

	_getch();

	return 0;
}