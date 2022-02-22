/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 21:12:14 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/22 16:41:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Form.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Form::Form(
	std::string const &name,
	bool const isSigned,
	int const gradeToSign,
	int const gradeToExec) :
	_name(name),
	_isSigned(isSigned),
	_gradeToSign(gradeToSign),
	_gradeToExec(gradeToExec)
{
	if (DEBUG)
		std::cout
		<< "Creating Form "
		<< this->_name
		<< std::boolalpha
		<< " (" << this->_isSigned << ")"
		<< " (" << this->_gradeToSign << ")"
		<< " (" << this->_gradeToExec << ")"
		<< std::endl;
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src) :
	_name(src._name),
	_isSigned(src._isSigned),
	_gradeToSign(src._gradeToSign),
	_gradeToExec(src._gradeToExec)
{
	if (DEBUG)
		std::cout
		<< "Creating Form "
		<< this->_name
		<< std::boolalpha
		<< " (" << this->_isSigned << ")"
		<< " (" << this->_gradeToSign << ")"
		<< " (" << this->_gradeToExec << ")"
		<< std::endl;
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw Form::GradeTooLowException();
}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

Form::~Form(void)
{
	if (DEBUG)
		std::cout
		<< "Destroying Form "
		<< this->_name
		<< std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

std::string const	&Form::getName(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Form::getName()"
		<< std::endl;
	return this->_name;
}

bool const	&Form::getIsSigned(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Form::getIsSigned()"
		<< std::endl;
	return this->_isSigned;
}

int const	&Form::getGradeToSign(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Form::getGradeToSign()"
		<< std::endl;
	return this->_gradeToSign;
}

int const	&Form::getGradeToExec(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Form::getGradeToExec()"
		<< std::endl;
	return this->_gradeToExec;
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

char const	*Form::GradeTooHighException::what(void) const throw()
{
	if (DEBUG)
		std::cout
		<< "Calling Form::GradeTooHighException::what()"
		<< std::endl;
	return "grade is too high";
}

char const	*Form::GradeTooLowException::what(void) const throw()
{
	if (DEBUG)
		std::cout
		<< "Calling Form::GradeTooLowException::what()"
		<< std::endl;
	return "grade is too low";
}

char const	*Form::AlreadySignedException::what(void) const throw()
{
	if (DEBUG)
		std::cout
		<< "Calling Form::AlreadySignedException::what()"
		<< std::endl;
	return "Form is already signed";
}

void	Form::beSigned(Bureaucrat const &b)
{
	if (DEBUG)
		std::cout
		<< "Calling Form::beSigned()"
		<< std::endl;
	if (b.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	if (this->_isSigned)
		throw Form::AlreadySignedException();
	this->_isSigned = true;
}

// ************************************************************************* //
//                                 Operators                                 //
// ************************************************************************* //

Form	&Form::operator=(Form const &rhs)
{
	if (DEBUG)
		std::cout
		<< "Calling Form::operator=()"
		<< std::endl;
	if (this != &rhs)
	{
		*(std::string *)&this->_name = rhs._name;
		this->_isSigned = rhs._isSigned;
		*(int *)&this->_gradeToSign = rhs._gradeToSign;
		*(int *)&this->_gradeToExec = rhs._gradeToExec;
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Form const &rhs)
{
	o << "Form:" << std::boolalpha << std::endl
	<< "\t" "name: " << rhs.getName() << std::endl
	<< "\t" "isSigned: " << rhs.getIsSigned() << std::endl
	<< "\t" "gradeToSign: " << rhs.getGradeToSign() << std::endl
	<< "\t" "gradeToExec: " << rhs.getGradeToExec() << std::endl;
	return o;
}
