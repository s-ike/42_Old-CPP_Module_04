/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:51:45 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/16 22:44:41 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define COLOR_RESET		"\033[m"
#define COLOR_RED		"\033[31m"

void	print_header(const std::string &str)
{
	std::cout << "\n[ " << str << " ]" << std::endl;
}

int	main()
{
	{
		print_header("subject test");
		const Animal*	j = new Dog();
		const Animal*	i = new Cat();

		delete j;//should not create a leak
		delete i;

		print_header("leaks Report");
		if (system("leaks -q a.out"))
			std::cout << COLOR_RED << "LEAK!" << COLOR_RESET << std::endl;
	}
	{
		print_header("array test");
		const int	array_max = 6;
		Animal		*animals[array_max];
		for (int i = 0; i < array_max; i++)
		{
			if (i < array_max / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		print_header("array test (makeSound())");
		std::cout << "animals[0]->makeSound(): "; animals[0]->makeSound();
		std::cout << "animals[3]->makeSound(): "; animals[3]->makeSound();

		print_header("array test destructor");
		for (int i = 0; i < array_max; i++)
			delete animals[i];

		print_header("leaks Report");
		if (system("leaks -q a.out"))
			std::cout << COLOR_RED << "LEAK!" << COLOR_RESET << std::endl;
	}
	{
		print_header("deep copy test preparation");
		Cat	*cat1 = new Cat();
		cat1->debug_ideas();
		for (int i = 0; i < std::numeric_limits<int>::max(); i++)
			;
		Cat	*cat2 = new Cat();
		cat2->debug_ideas();

		print_header("deep copy test");
		*cat1 = *cat2;
		cat1->debug_ideas();

		print_header("deep copy test destruction");
		delete cat1;
		delete cat2;

		print_header("leaks Report");
		if (system("leaks -q a.out"))
			std::cout << COLOR_RED << "LEAK!" << COLOR_RESET << std::endl;
	}
	{
		print_header("constructor test");
		const Cat*	cat1 = new Cat();
		Cat			cat2(*cat1);
		delete cat1;

		print_header("leaks Report");
		if (system("leaks -q a.out"))
			std::cout << COLOR_RED << "LEAK!" << COLOR_RESET << std::endl;
	}
	{
		print_header("assignment test");
		const Cat*	cat1 = new Cat();
		Cat			cat2;
		cat2 = *cat1;
		delete cat1;

		print_header("leaks Report");
		if (system("leaks -q a.out"))
			std::cout << COLOR_RED << "LEAK!" << COLOR_RESET << std::endl;
	}
}