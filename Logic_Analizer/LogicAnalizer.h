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

	int analisis(std::string& logic)
	{
		compresser(logic);
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

	std::string transformedLogic = {};

private:

	int logicTransformationMaxLength = 5;
	
	std::list <int> errorIndexes = {};

	std::map <std::string, std::string> logicTransformation
	{
		{"!", "<EXCLA>"},
		{"&", "<AMPER>"},
		{"#", "<SHARP>"},
		{"for", "<STA_C>"},
		{"to", "<MID_C>"},
		{"do", "<END_C>"},
		{";", "<CLOSE>"},
		{"begin", "<B_BEG>"},
		{"end", "<B_END>"},
		{"var", "<VARIA>"},
		{":=", "<ASSIG>"}
	};

	void compresser(std::string& logic)
	{
		for(int i = logic.find(' '); i > 0; i = logic.find(' '))
			logic.erase(logic.begin() + i);

		for (int i = logic.find('\t'); i > 0; i = logic.find('\t'))
			logic.erase(logic.begin() + i);

	}
};

#endif