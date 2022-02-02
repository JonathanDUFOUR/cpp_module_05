/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:48:31 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/02 15:53:43 by jodufour         ###   ########.fr       */
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

// ************************************************************************** //
//                          Private Member Functions                          //
// ************************************************************************** //

AForm	*Intern::makeShrubberyCreationForm(std::string const &target)
{
	std::cout
	<< "Intern creates ShrubberyCreationForm"
	<< std::endl;
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::makeRobotomyRequestForm(std::string const &target)
{
	std::cout
	<< "Intern creates RobotomyRequestForm"
	<< std::endl;
	return new RobotomyRequestForm(target);
}

AForm	*Intern::makePresidentialPardonForm(std::string const &target)
{
	std::cout
	<< "Intern creates PresidentialPardonForm"
	<< std::endl;
	return new PresidentialPardonForm(target);
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

AForm	*Intern::makeForm(std::string const &name, std::string const &target) const
{
	int	i;

	for (i = 0 ; lookup[i].maker ; ++i)
		if (!name.compare(lookup[i].name))
			return lookup[i].maker(target);
	throw Intern::UnknownFormException();
}

char const	*Intern::UnknownFormException::what(void) const throw()
{
	return "wanted form is unknown";
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

// ************************************************************************** //
//                             Private Attributes                             //
// ************************************************************************** //

t_nameForm	Intern::lookup[] = {
	{"shrubbery creation", makeShrubberyCreationForm},
	{"robotomy request", makeRobotomyRequestForm},
	{"presidential pardon", makePresidentialPardonForm},
	{"", NULL}
};
