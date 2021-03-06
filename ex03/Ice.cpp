/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 00:56:14 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/19 13:16:38 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "def_color.h"
#include "ICharacter.hpp"
#include "Ice.hpp"

/* ************************************************************************** */
/*   orthodox canonical form                                                  */
/* ************************************************************************** */

Ice::Ice()
	: AMateria("ice")
{
	std::cout << COLOR_CYAN "Ice constructor called" COLOR_RESET << std::endl;
}

Ice::Ice(const Ice& other)
	: AMateria(other._type)
{
	std::cout << COLOR_CYAN "Ice copy constructor called" COLOR_RESET << std::endl;
}

Ice&	Ice::operator=(const Ice& other)
{
	std::cout << COLOR_CYAN "Ice assignation operator called" COLOR_RESET << std::endl;
	(void)other;
	return *this;
}

Ice::~Ice()
{
	std::cout << COLOR_CYAN "Ice destructor called" COLOR_RESET << std::endl;
}

/* ************************************************************************** */
/*   methods                                                                  */
/* ************************************************************************** */

AMateria*	Ice::clone() const
{
	return new Ice();
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
