/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:48:31 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/01 22:16:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Intern.hpp"
#include "class/ShrubberyCreationForm.hpp"
#include "class/RobotomyRequestForm.hpp"
#include "class/PresidentialPardonForm.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Intern::Intern(void)
{
	std::cout
	<< "Spawning Intern"
	<< std::endl;
}

Intern::Intern(Intern const &src)
{
	std::cout
	<< "Spawning Intern"
	<< std::endl;
	*this = src;
}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

Intern::~Intern(void)
{
	std::cout
	<< "Killing Intern"
	<< std::endl;
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

AForm	*Intern::makeForm(std::string const &name, std::string const &target) const
{
	(void)name;
	return new ShrubberyCreationForm(target);
	return new RobotomyRequestForm(target);
	return new PresidentialPardonForm(target);
}

// ************************************************************************** //
//                             Operator Overloads                             //
// ************************************************************************** //

Intern	&Intern::operator=(Intern const &rhs __attribute__((unused)))
{
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Intern const &rhs __attribute__((unused)))
{
	o << "Intern:" << std::endl;
	return o;
}
