/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 21:12:14 by jodufour          #+#    #+#             */
/*   Updated: 2022/03/02 20:05:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/AForm.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

AForm::AForm(
	std::string const &name,
	bool const isSigned,
	uint const gradeToSign,
	uint const gradeToExec) :
	_name(name),
	_isSigned(isSigned),
	_gradeToSign(gradeToSign),
	_gradeToExec(gradeToExec)
{
	if (DEBUG)
		std::cout
		<< "Creating AForm "
		<< this->_name
		<< std::boolalpha
		<< " (" << this->_isSigned << ")"
		<< " (" << this->_gradeToSign << ")"
		<< " (" << this->_gradeToExec << ")"
		<< std::endl;
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw AForm::GradeTooHighException();
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &src) :
	_name(src._name),
	_isSigned(src._isSigned),
	_gradeToSign(src._gradeToSign),
	_gradeToExec(src._gradeToExec)
{
	if (DEBUG)
		std::cout
		<< "Creating AForm "
		<< this->_name
		<< std::boolalpha
		<< " (" << this->_isSigned << ")"
		<< " (" << this->_gradeToSign << ")"
		<< " (" << this->_gradeToExec << ")"
		<< std::endl;
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw AForm::GradeTooHighException();
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw AForm::GradeTooLowException();
}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

AForm::~AForm(void)
{
	if (DEBUG)
		std::cout
		<< "Destroying AForm "
		<< this->_name
		<< std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

std::string const	&AForm::getName(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling AForm::getName()"
		<< std::endl;
	return this->_name;
}

bool const	&AForm::getIsSigned(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling AForm::getIsSigned()"
		<< std::endl;
	return this->_isSigned;
}

uint const	&AForm::getGradeToSign(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling AForm::getGradeToSign()"
		<< std::endl;
	return this->_gradeToSign;
}

uint const	&AForm::getGradeToExec(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling AForm::getGradeToExec()"
		<< std::endl;
	return this->_gradeToExec;
}

void	AForm::setIsSigned(bool const issigned)
{
	if (DEBUG)
		std::cout
		<< "Calling AForm::setIsSigned()"
		<< std::endl;
	this->_isSigned = issigned;
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

char const	*AForm::GradeTooHighException::what(void) const throw()
{
	if (DEBUG)
		std::cout
		<< "Calling AForm::GradeTooHighException::what()"
		<< std::endl;
	return "grade is too high";
}

char const	*AForm::GradeTooLowException::what(void) const throw()
{
	if (DEBUG)
		std::cout
		<< "Calling AForm::GradeTooLowException::what()"
		<< std::endl;
	return "grade is too low";
}

char const	*AForm::AlreadySignedException::what(void) const throw()
{
	if (DEBUG)
		std::cout
		<< "Calling AForm::AlreadySignedException::what()"
		<< std::endl;
	return "AForm is already signed";
}

// ************************************************************************* //
//                                 Operators                                 //
// ************************************************************************* //

AForm	&AForm::operator=(AForm const &rhs)
{
	if (DEBUG)
		std::cout
		<< "Calling AForm::operator=()"
		<< std::endl;
	if (this != &rhs)
	{
		*(std::string *)&this->_name = rhs._name;
		this->_isSigned = rhs._isSigned;
		*(uint *)&this->_gradeToSign = rhs._gradeToSign;
		*(uint *)&this->_gradeToExec = rhs._gradeToExec;
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, AForm const &rhs)
{
	o << "AForm:" << std::boolalpha << std::endl
	<< "\t" "name: " << rhs.getName() << std::endl
	<< "\t" "isSigned: " << rhs.getIsSigned() << std::endl
	<< "\t" "gradeToSign: " << rhs.getGradeToSign() << std::endl
	<< "\t" "gradeToExec: " << rhs.getGradeToExec() << std::endl;
	return o;
}
