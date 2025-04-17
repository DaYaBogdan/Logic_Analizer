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

	int analisis(std::string logic)
	{
		for (int i = 0; i < logic.length(); ++i)
		{
			if (isalpha(logic[i]) && isupper(logic[i])) 
			{
				transformedLogic.append("<A>");
			}

			else if (isdigit(logic[i])) 
			{
				transformedLogic.append("<D>");
			}

			else if (1) 
			{
				int flag = 1;
				for (int j = 0; i + j < logic.length() && j < logicTransformationMaxLength; ++j)
				{
					if (logicTransformation[logic.substr(i, j + 1)] != "")
					{
						transformedLogic.append(logicTransformation[logic.substr(i, j + 1)]);
						i += j;
						flag = 0;
						break;
					}
				}
				if (flag)
				{
					errorIndexes.push_back(i + 1);
				}
			}
		}

		return 0;
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

	int logicTransformationMaxLength = 5;
	
	std::list <int> errorIndexes = {};

	std::string transformedLogic = {};

	std::map <std::string, std::string> logicTransformation
	{
		{"!", "<EXCLAM>"},
		{"&", "<AMPER>"},
		{"#", "<SHARP>"},
		{"for", "<ST_C>"},
		{"to", "<MID_C>"},
		{"do", "<END_C>"},
		{";", "<CLOSE>"},
		{"begin", "<B_BEG>"},
		{"end", "<B_END>"},
		{"var", "<VAR>"},
		{":=", "<ASSIGN>"}
	};
};

#endif