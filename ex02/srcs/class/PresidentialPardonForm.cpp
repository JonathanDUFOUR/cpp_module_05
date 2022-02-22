/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:30:28 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/22 21:43:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/PresidentialPardonForm.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
	AForm("presidential pardon", false, 25, 5),
	_target(target)
{
	if (DEBUG)
		std::cout
		<< "Creating PresidentialPardonForm "
		<< this->getName()
		<< " (" << this->getGradeToSign() << ")"
		<< " (" << this->getGradeToExec() << ")"
		<< " (" << this->_target << ")"
		<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
	AForm(src),
	_target(src._target)
{
	if (DEBUG)
		std::cout
		<< "Creating PresidentialPardonForm "
		<< this->getName()
		<< " (" << this->getGradeToSign() << ")"
		<< " (" << this->getGradeToExec() << ")"
		<< " (" << this->_target << ")"
		<< std::endl;
}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	if (DEBUG)
		std::cout
		<< "Destroying PresidentialPardonForm "
		<< this->getName()
		<< std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

std::string const	&PresidentialPardonForm::getTarget(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling PresidentialPardonForm::getTarget()"
		<< std::endl;
	return this->_target;
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

void	PresidentialPardonForm::beSigned(Bureaucrat const &b)
{
	if (DEBUG)
		std::cout
		<< "Calling PresidentialPardonForm::beSigned()"
		<< std::endl;
	if (b.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	if (this->getIsSigned())
		throw AForm::AlreadySignedException();
	this->setIsSigned(true);
}

void	PresidentialPardonForm::execute(Bureaucrat const &b) const
{
	if (DEBUG)
		std::cout
		<< "Calling PresidentialPardonForm::execute()"
		<< std::endl;
	if (b.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	std::cout
	<< this->_target
	<< " has been pardoned by Zaphod Beeblebrox"
	<< std::endl;
}

// ************************************************************************* //
//                                 Operators                                 //
// ************************************************************************* //

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (DEBUG)
		std::cout
		<< "Calling PresidentialPardonForm::operator=()"
		<< std::endl;
	if (this != &rhs)
	{
		this->AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm const &rhs)
{
	o << "PresidentialPardonForm:" << std::boolalpha << std::endl
	<< "\t" "name: " << rhs.getName() << std::endl
	<< "\t" "isSigned: " << rhs.getIsSigned() << std::endl
	<< "\t" "gradeToSign: " << rhs.getGradeToSign() << std::endl
	<< "\t" "gradeToExec: " << rhs.getGradeToExec() << std::endl
	<< "\t" "target: " << rhs.getTarget() << std::endl;
	return o;
}
