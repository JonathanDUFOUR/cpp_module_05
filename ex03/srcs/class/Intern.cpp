/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:48:31 by jodufour          #+#    #+#             */
/*   Updated: 2022/03/02 20:07:59 by jodufour         ###   ########.fr       */
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
	if (DEBUG)
		std::cout
		<< "Creating Intern"
		<< std::endl;
}

Intern::Intern(Intern const &src __attribute__((unused)))
{
	if (DEBUG)
		std::cout
		<< "Creating Intern"
		<< std::endl;
}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

Intern::~Intern(void)
{
	if (DEBUG)
		std::cout
		<< "Destroying Intern"
		<< std::endl;
}

// ************************************************************************** //
//                          Private Member Functions                          //
// ************************************************************************** //

AForm	*Intern::makeShrubberyCreationForm(std::string const &target)
{
	if (DEBUG)
		std::cout
		<< "Calling Intern::makeShrubberyCreationForm()"
		<< std::endl;
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::makeRobotomyRequestForm(std::string const &target)
{
	if (DEBUG)
		std::cout
		<< "Calling Intern::makeRobotomyRequestForm()"
		<< std::endl;
	return new RobotomyRequestForm(target);
}

AForm	*Intern::makePresidentialPardonForm(std::string const &target)
{
	if (DEBUG)
		std::cout
		<< "Calling Intern::makePresidentialPardonForm()"
		<< std::endl;
	return new PresidentialPardonForm(target);
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

AForm	*Intern::makeForm(std::string const &name, std::string const &target) const
{
	int	i;

	if (DEBUG)
		std::cout
		<< "Calling Intern::makeForm()"
		<< std::endl;
	for (i = 0 ; _lookup[i].maker ; ++i)
		if (!name.compare(_lookup[i].name))
			return _lookup[i].maker(target);
	throw Intern::UnknownFormException();
}

char const	*Intern::UnknownFormException::what(void) const throw()
{
	if (DEBUG)
		std::cout
		<< "Calling Intern::UnknownFormException::what()"
		<< std::endl;
	return "wanted form is unknown";
}

// ************************************************************************* //
//                                 Operators                                 //
// ************************************************************************* //

Intern	&Intern::operator=(Intern const &rhs __attribute__((unused)))
{
	if (DEBUG)
		std::cout
		<< "Calling Intern::operator=()"
		<< std::endl;
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

t_mkForm	Intern::_lookup[] = {
	{std::string("shrubbery creation"), Intern::makeShrubberyCreationForm},
	{std::string("robotomy request"), Intern::makeRobotomyRequestForm},
	{std::string("presidential pardon"), Intern::makePresidentialPardonForm},
	{std::string(""), NULL}
};
