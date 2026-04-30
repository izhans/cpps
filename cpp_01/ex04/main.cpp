#include <iostream>
#include <string>
#include <fstream>

static void ft_replace(std::string &str, std::string needle, std::string replace);

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Use as: ./replace <filename> <old string> <new string>" << std::endl;
		return 1;
	}

	std::string fileInName = argv[1];
	std::string fileOutName = fileInName + ".replace";
	
	std::ifstream fileIn(fileInName.c_str()); 
	std::ofstream fileOut(fileOutName.c_str());

	if (!fileIn.is_open() || !fileOut.is_open())
	{
		std::cout << "Problem found while opening/creating file" << std::endl;
		fileIn.close();
		fileOut.close();
		return 1;
	}
	
	std::string line;
	std::string needle = argv[2];
	std::string replace = argv[3];

	while (std::getline(fileIn, line))
	{
		ft_replace(line, needle, replace);
		fileOut << line;

		if (!fileIn.eof())
			fileOut << std::endl;
	}

	fileIn.close();
    fileOut.close();
}

static void ft_replace(std::string &str, std::string needle, std::string replace)
{
	if (needle.empty())
		return ;
	
	std::size_t found = 0;

	while ((found = str.find(needle, found)) != std::string::npos)
	{		
		str.erase(found, needle.length());
		str.insert(found, replace);

		found += replace.length();
	}
}

