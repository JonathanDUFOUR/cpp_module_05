/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 21:12:14 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/07 04:25:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Form.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Form::Form(void) :
	_name(std::string("defaultName")),
	_isSigned(false),
	_gradeToSign(150),
	_gradeToExec(150)
{
	std::cout
	<< "Writing Form "
	<< this->_name
	<< (this->_isSigned ? " (true)" : " (false)")
	<< " (" << this->_gradeToSign << ")"
	<< " (" << this->_gradeToExec << ")"
	<< std::endl;
}

Form::Form(Form const &src) :
	_name(src._name),
	_isSigned(src._isSigned),
	_gradeToSign(src._gradeToSign),
	_gradeToExec(src._gradeToExec)
{
	std::cout
	<< "Writing Form "
	<< this->_name
	<< (this->_isSigned ? " (true)" : " (false)")
	<< " (" << this->_gradeToSign << ")"
	<< " (" << this->_gradeToExec << ")"
	<< std::endl;
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw Form::GradeTooLowException();
	*this = src;
}

Form::Form(
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
	<< "Writing Form "
	<< this->_name
	<< (this->_isSigned ? " (true)" : " (false)")
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
	std::cout
	<< "Burning Form "
	<< this->_name
	<< std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

std::string const	&Form::getName(void) const
{
	return this->_name;
}

bool const	&Form::getIsSigned(void) const
{
	return this->_isSigned;
}

int const	&Form::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

int const	&Form::getGradeToExec(void) const
{
	return this->_gradeToExec;
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

void	Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	if (this->_isSigned)
		throw Form::AlreadySignedException();
	this->_isSigned = true;
}

char const	*Form::GradeTooHighException::what(void) const throw()
{
	return "grade is too high";
}

char const	*Form::GradeTooLowException::what(void) const throw()
{
	return "grade is too low";
}

char const	*Form::AlreadySignedException::what(void) const throw()
{
	return "Form is already signed";
}

// ************************************************************************* //
//                                 Operators                                 //
// ************************************************************************* //

Form	&Form::operator=(Form const &rhs)
{
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
	o << "Form:" << std::endl
	<< "\t" "name: " << rhs.getName() << std::endl
	<< "\t" "isSigned: " << (rhs.getIsSigned() ? "true" : "false") << std::endl
	<< "\t" "gradeToSign: " << rhs.getGradeToSign() << std::endl
	<< "\t" "gradeToExec: " << rhs.getGradeToExec() << std::endl;
	return o;
}
