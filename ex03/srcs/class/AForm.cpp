/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 21:12:14 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/07 04:27:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/AForm.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

AForm::AForm(void) :
	_name(std::string("defaultName")),
	_isSigned(false),
	_gradeToSign(150),
	_gradeToExec(150)
{
	std::cout
	<< "Writing AForm "
	<< this->_name
	<< (this->_isSigned ? " (true)" : " (false)")
	<< " (" << this->_gradeToSign << ")"
	<< " (" << this->_gradeToExec << ")"
	<< std::endl;
}

AForm::AForm(AForm const &src) :
	_name(src._name),
	_isSigned(src._isSigned),
	_gradeToSign(src._gradeToSign),
	_gradeToExec(src._gradeToExec)
{
	std::cout
	<< "Writing AForm "
	<< this->_name
	<< (this->_isSigned ? " (true)" : " (false)")
	<< " (" << this->_gradeToSign << ")"
	<< " (" << this->_gradeToExec << ")"
	<< std::endl;
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw AForm::GradeTooHighException();
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw AForm::GradeTooLowException();
	*this = src;
}

AForm::AForm(
	std::string const name,
	bool const isSigned,
	int const gradeToSign,
	int const gradeToExec) :
	_name(name),
	_isSigned(isSigned),
	_gradeToSign(gradeToSign),
	_gradeToExec(gradeToExec)
{
	std::cout
	<< "Writing AForm "
	<< this->_name
	<< (this->_isSigned ? " (true)" : " (false)")
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
	std::cout
	<< "Burning AForm "
	<< this->_name
	<< std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

std::string const	&AForm::getName(void) const
{
	return this->_name;
}

bool const	&AForm::getIsSigned(void) const
{
	return this->_isSigned;
}

int const	&AForm::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

int const	&AForm::getGradeToExec(void) const
{
	return this->_gradeToExec;
}

void	AForm::setName(std::string const &name)
{
	*(std::string *)&this->_name = name;
}

void	AForm::setIsSigned(bool const isSigned)
{
	this->_isSigned = isSigned;
}

void	AForm::setGradeToSign(int const gradeToSign)
{
	*(int *)&this->_gradeToSign = gradeToSign;
}

void	AForm::setGradeToExec(int const gradeToExec)
{
	*(int *)&this->_gradeToExec = gradeToExec;
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

char const	*AForm::GradeTooHighException::what(void) const throw()
{
	return "grade is too high";
}

char const	*AForm::GradeTooLowException::what(void) const throw()
{
	return "grade is too low";
}

char const	*AForm::AlreadySignedException::what(void) const throw()
{
	return "AForm is already signed";
}

// ************************************************************************* //
//                                 Operators                                 //
// ************************************************************************* //

AForm	&AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
	{
		this->setName(rhs._name);
		this->setIsSigned(rhs._isSigned);
		this->setGradeToSign(rhs._gradeToSign);
		this->setGradeToExec(rhs._gradeToExec);
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, AForm const &rhs)
{
	o << "AForm:" << std::endl
	<< "\t" "name: " << rhs.getName() << std::endl
	<< "\t" "isSigned: " << (rhs.getIsSigned() ? "true" : "false") << std::endl
	<< "\t" "gradeToSign: " << rhs.getGradeToSign() << std::endl
	<< "\t" "gradeToExec: " << rhs.getGradeToExec() << std::endl;
	return o;
}
