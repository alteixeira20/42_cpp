#include <string>
#include <iostream>
#include <fstream>

bool	readFile(const std::string &filename, std::string &content)
{
	std::ifstream	inputFile(filename.c_str());

	if (!inputFile.is_open())
		return (false);

	std::string	line;
	while (std::getline(inputFile, line))
	{
		content += line;
		content += '\n';
	}
	inputFile.close();
	return (true);
}

static void	searchAndReplace(std::string &content,
			     const std::string &search,
			     const std::string &replace)
{
	size_t	pos = 0;

	while ((pos = content.find(search, pos)) != std::string::npos)
	{
		content.erase(pos, search.length());
		content.insert(pos, replace);
		pos += replace.length();
	}
}

static bool	writeFile(const std::string &filename, const std::string &content)
{
	std::ofstream	outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open())
		return (false);
	outputFile << content;
	outputFile.close();
	return (true);
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./op_sed <filename> <search> <replace>\n";
		return (1);
	}
	std::string	filename = av[1];
	std::string	search = av[2];
	std::string	replace = av[3];
	
	if (search.empty())
	{
		std::cerr << "Error: search string cannot be empty\n";
		return (1);
	}

	std::string	content;
	if (!readFile(filename, content))
	{
		std::cerr << "Error: could not open input file\n";
		return (1);
	}
	if (content.empty())
	{
		std::cerr << "Error: the input file is empty\n";
		return (1);
	}
	searchAndReplace(content, search, replace);
	if (!writeFile(filename, content))
	{
		std::cerr << "Error: could not create output file\n";
		return (1);
	}
	return (0);
}
