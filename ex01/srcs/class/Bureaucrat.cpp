/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:48:18 by jodufour          #+#    #+#             */
/*   Updated: 2022/03/02 19:52:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Bureaucrat.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Bureaucrat::Bureaucrat(std::string const &name, uint const grade) :
	_name(name),
	_grade(grade)
{
	if (DEBUG)
		std::cout
		<< "Creating Bureaucrat "
		<< this->_name
		<< " (" << this->_grade << ")"
		<< std::endl;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) :
	_name(src._name),
	_grade(src._grade)
{
	if (DEBUG)
		std::cout
		<< "Creating Bureaucrat "
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
	if (DEBUG)
		std::cout
		<< "Destroying Bureaucrat "
		<< this->_name
		<< std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

std::string const	&Bureaucrat::getName(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Bureaucrat::getName()"
		<< std::endl;
	return this->_name;
}

uint const	&Bureaucrat::getGrade(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Bureaucrat::getGrade()"
		<< std::endl;
	return this->_grade;
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

void	Bureaucrat::decrementGrade(void)
{
	if (DEBUG)
		std::cout
		<< "Calling Bureaucrat::decrementGrade()"
		<< std::endl;
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	++this->_grade;
}

void	Bureaucrat::incrementGrade(void)
{
	if (DEBUG)
		std::cout
		<< "Calling Bureaucrat::incrementGrade()"
		<< std::endl;
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	--this->_grade;
}

void	Bureaucrat::signForm(Form &f) const
{
	if (DEBUG)
		std::cout
		<< "Calling Bureaucrat::signForm()"
		<< std::endl;
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
	catch (std::exception const &e)
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
	if (DEBUG)
		std::cout
		<< "Calling Bureaucrat::GradeTooHighException::what()"
		<< std::endl;
	return "grade is too high";
}

char const	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	if (DEBUG)
		std::cout
		<< "Calling Bureaucrat::GradeTooLowException::what()"
		<< std::endl;
	return "grade is too low";
}

// ************************************************************************* //
//                                 Operators                                 //
// ************************************************************************* //

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (DEBUG)
		std::cout
		<< "Calling Bureaucrat::operator=()"
		<< std::endl;
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
