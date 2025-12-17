#include "Brain.hpp"


/*
 * Default constructor.
 * Initializes an empty Brain.
 */
Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

/*
 * Copy constructor.
 * Copies all 100 ideas from another Brain.
 */
Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

/*
 * Copy assignment operator.
 * Replaces this Brain's ideas with another's.
 */
Brain	&Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;

	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
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
