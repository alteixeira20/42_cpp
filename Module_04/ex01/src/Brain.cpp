#include "Brain.hpp"


// Default Constructor
Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

// Copy Constructor
Brain::Brain(const Brain &other)
{
	int	i;

	std::cout << "Brain copy constructor called" << std::endl;
	i = 0;
	while (i < 100)
	{
		ideas[i] = other.ideas[i];
		i++;
	}
}

// Copy Assignment
Brain	&Brain::operator=(const Brain &other)
{
	int	i;

	std::cout << "Copy Assignment Operator called -" << std::endl;

	if (this != &other)
	{
		i = 0;
		while (i < 100)
		{
			ideas[i] = other.ideas[i];
			i++;
		}
	}
	return (*this);
}

// Destructor
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

// Getters and Setters
std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		return ("This brain doesnt have space for that much ideas!");
	return ideas[index];
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index < 0 || index >= 100)
		return;
	ideas[index] = idea;
}

