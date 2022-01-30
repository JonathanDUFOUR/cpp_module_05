/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:48:18 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/30 19:43:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Bureaucrat.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Bureaucrat::Bureaucrat(void) :
	_grade(150),
	_name("defaultName")
{
	std::cout
	<< "Creating Bureaucrat "
	<< this->_name
	<< "("
	<< this->_grade
	<< ")"
	<< std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) :
	_grade(src._grade),
	_name(src._name)
{
	std::cout
	<< "Creating Bureaucrat "
	<< this->_name
	<< "("
	<< this->_grade
	<< ")"
	<< std::endl;
	*this = src;
}

Bureaucrat::Bureaucrat(int const grade, std::string const name) :
	_grade(grade),
	_name(name)
{
	if (grade > 150 || grade < 1)
		throw ;
	std::cout
	<< "Creating Bureaucrat "
	<< this->_name
	<< "("
	<< this->_grade
	<< ")"
	<< std::endl;
}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

Bureaucrat::~Bureaucrat(void)
{
	std::cout
	<< "Destroying Bureaucrat "
	<< this->_name
	<< std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

int const	&Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

std::string const	&Bureaucrat::getName(void) const
{
	return this->_name;
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

void	Bureaucrat::decrementGrade(void)
{
	++this->_grade;
}

void	Bureaucrat::incrementGrade(void)
{
	--this->_grade;
}

// ************************************************************************** //
//                             Operator Overloads                             //
// ************************************************************************** //

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
		*(std::string *)&this->_name = rhs._name;
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << "Bureaucrat:" << std::endl
	<< "\t" "name: " << rhs.getName() << std::endl
	<< "\t" "grade: " << rhs.getGrade() << std::endl;
	return o;
}
