#include "SyntaxisAnalizer.h"
#include "VisualMenu.h"
#include "iostream"

int inputLogic(std::string&);
int showLogic(std::string&);
int syntaxis(std::string& logic);

int main()
{
	std::string logic;
	VisualMenu <std::string&, int> menu { logic };

	menu.addElement({ 4, 4, "Input Logic", inputLogic });
	menu.addElement({ 4, 5, "Show Logic", showLogic });
	menu.addElement({ 4, 6, "Syntax Analisis", syntaxis });
	menu.openMenu();
}

int inputLogic(std::string& logic)
{
	std::getline(std::cin, logic);
	return 0;
}

int syntaxis(std::string& logic)
{
	SyntaxisAnalizer analizer;

	analizer.startAnalisis(logic);

	_getch();

	return 0;
}

int showLogic(std::string& logic)
{
	LogicAnalizer analizer;

	analizer.analisis(logic);
		for (const auto& elem : analizer.returnErrors())
			std::cout << "ERROR ON INDEX: " << elem << std::endl;

	std::cout << analizer.transformedLogic << std::endl;

	_getch();

	return 0;
}