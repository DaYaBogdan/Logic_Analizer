#ifndef LOGICANALIZER
#define LOGICANALIZER

#include <map>
#include <string>
#include <list>

class LogicAnalizer
{
public:

	LogicAnalizer() {};
	~LogicAnalizer() {};

	int cut()
	{
		std::string 
		for (int i = 0; i < logic.length(); ++i)
	}

	int analisis(std::string logic)
	{
		int flag = 0;
		
		for (int i = 0; i < logic.length(); ++i)
		{
			if (isalpha(logic[i]) && isupper(logic[i])) 
			{
				transformedLogic.append("<ALPHA>");
			}

			else if (isdigit(logic[i])) 
			{
				transformedLogic.append("<DIGIT>");
			}

			else if (1) 
			{		
				int j = 0;
				for (; i + j < logic.length() && j < logicTransformationMaxLength; ++j)
				{
					if (logicTransformation[logic.substr(i, j + 1)] != "")
					{
						transformedLogic.append(logicTransformation[logic.substr(i, j + 1)]);
						i += j;
						break;
					}
				}
				if (logicTransformation[logic.substr(i, j + 1)] == "")
				{
					errorIndexes.push_back(i + 1);
					flag = 1;
				}
			}
		}

		return flag;
	}



	std::list <int> returnErrors()
	{
		return errorIndexes;
	}

	std::string returnTransformedLogic()
	{
		return transformedLogic;
	}

private:

	int logicTransformationMaxLength = 6;
	
	std::list <int> errorIndexes = {};

	std::string transformedLogic = {};

	std::map <std::string, std::string> logicTransformation
	{
		{"!", "<EXCLAMATION_LEXEMA>"},
		{"&", "<AMPERSANT_LEXEMA>"},
		{"#", "<SHARP_LEXEMA>"},
		{"for", "<START_CYCLE_LEXEMA>"},
		{"to", "<MIDDLE_CYCLE_LEXEMA>"},
		{"do", "<END_CYCLE_LEXEMA>"},
		{";", "<END_LINE_LEXEMA>"},
		{"begin", "<BEGIN_LEXEMA>"},
		{"end", "<END_LEXEMA>"},
		{"var", "<VARIABLE_LEXEMA>"},
		{":=", "<ASSIGNMENT_LEXEMA>"}
	};
};

#endif