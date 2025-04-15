#include "LogicAnalizer.h"
#include "iostream"

int inputLogic(std::string& logic)
{
	std::cin >> logic;
	return 0;
}



int main()
{
	LogicAnalizer analizer;
	std::string logic;

	inputLogic(logic);

	if(analizer.analisis(logic))
		for (const auto& elem : analizer.returnErrors())
			std::cout << "ERROR ON INDEX: " << elem << std::endl;

	std::cout << analizer.returnTransformedLogic() << std::endl;

	return 0;
}