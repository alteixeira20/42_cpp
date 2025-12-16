#ifndef TESTER_HPP
# define TESTER_HPP

#include <iostream>
#include <cstdlib>
#include "Brain.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	test_deepcopy_dog(void);
void	test_deepcopy_cat(void);
void	test_polymorphism(int count);
void    test_wrong_polymorphism(void);

#endif
