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

	/*int cut()
	{
		std::string cuttedlogic = {};
		int primary = 0;

		for (int i = 0; i < transformedLogic.length(); ++i)
		{
			if (transformedLogic[i] == '<')
			{
				if (transformedLogic.substr(i, 7) == "<ALPHA>" || transformedLogic.substr(i, 7) == "<DIGIT>")
				{
					primary = 1;
					i += 6;
				}

				else if (primary)
				{
					primary = 0;
					cuttedlogic.append("<PRIMARY>");
				}
				
				else 
				{
					cuttedlogic.append(&transformedLogic[i]);
				}
			}
			else cuttedlogic.append(&transformedLogic[i]);
		}

		if (primary)
		{
			cuttedlogic.append("<PRIMARY>");
		}

		transformedLogic = cuttedlogic;

		return 0;
	}*/

	int analisis(std::string logic)
	{
		int flag = 1;
		
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
		{"!", "<EXCLAMATION>"},
		{"&", "<AMPERSANT>"},
		{"#", "<SHARP>"},
		{"for", "<START_CYCLE>"},
		{"to", "<MIDDLE_CYCLE>"},
		{"do", "<END_CYCLE>"},
		{";", "<END_LINE>"},
		{"begin", "<BLOCK_BEGIN>"},
		{"end", "<BLOCK_END>"},
		{"var", "<VARIABLE>"},
		{":=", "<ASSIGNMENT>"}
	};
};

#endif