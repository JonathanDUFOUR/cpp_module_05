/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:48:18 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/07 04:24:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Bureaucrat.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Bureaucrat::Bureaucrat(void) :
	_name(std::string("defaultName")),
	_grade(150)
{
	std::cout
	<< "Spawning Bureaucrat "
	<< this->_name
	<< " (" << this->_grade << ")"
	<< std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) :
	_name(src._name),
	_grade(src._grade)
{
	std::cout
	<< "Spawning Bureaucrat "
	<< this->_name
	<< " (" << this->_grade << ")"
	<< std::endl;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	*this = src;
}

Bureaucrat::Bureaucrat(std::string const &name, int const grade) :
	_name(name),
	_grade(grade)
{
	std::cout
	<< "Spawning Bureaucrat "
	<< this->_name
	<< " (" << this->_grade << ")"
	<< std::endl;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

Bureaucrat::~Bureaucrat(void)
{
	std::cout
	<< "Killing Bureaucrat "
	<< this->_name
	<< std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

std::string const	&Bureaucrat::getName(void) const
{
	return this->_name;
}

int const	&Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	++this->_grade;
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	--this->_grade;
}

void	Bureaucrat::signForm(Form &f) const
{
	try
	{
		f.beSigned(*this);
		std::cout
		<< "Bureaucrat "
		<< this->_name
		<< " signed Form "
		<< f.getName()
		<< std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr
		<< "Error: Bureaucrat "
		<< this->_name
		<< " couldn't sign Form "
		<< f.getName()
		<< " because "
		<< e.what()
		<< std::endl;
	}
}

char const	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "grade is too high";
}

char const	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "grade is too low";
}

// ************************************************************************* //
//                                 Operators                                 //
// ************************************************************************* //

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
