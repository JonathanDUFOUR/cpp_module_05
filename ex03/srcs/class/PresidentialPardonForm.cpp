/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:30:28 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/07 04:27:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/PresidentialPardonForm.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm("presidential pardon", false, 25, 5),
	_target("defaultTarget")
{
	std::cout
	<< "Writing PresidentialPardonForm "
	<< this->getName()
	<< " (" << this->getGradeToSign() << ")"
	<< " (" << this->getGradeToExec() << ")"
	<< " -> " << this->_target
	<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
	AForm(src.getName(), src.getIsSigned(), src.getGradeToSign(), src.getGradeToExec()),
	_target(src._target)
{
	std::cout
	<< "Writing PresidentialPardonForm "
	<< this->getName()
	<< " (" << this->getGradeToSign() << ")"
	<< " (" << this->getGradeToExec() << ")"
	<< " -> " << this->_target
	<< std::endl;
	*this = src;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
	AForm("presidential pardon", false, 25, 5),
	_target(target)
{
	std::cout
	<< "Writing PresidentialPardonForm "
	<< this->getName()
	<< " (" << this->getGradeToSign() << ")"
	<< " (" << this->getGradeToExec() << ")"
	<< " -> " << this->_target
	<< std::endl;
}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout
	<< "Burning PresidentialPardonForm "
	<< this->getName()
	<< std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

std::string const	&PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

void	PresidentialPardonForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	if (this->getIsSigned())
		throw AForm::AlreadySignedException();
	this->setIsSigned(true);
}

void	PresidentialPardonForm::execute(Bureaucrat const &b) const
{
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
	if (this != &rhs)
	{
		this->setName(rhs.getName());
		this->setIsSigned(rhs.getIsSigned());
		this->setGradeToSign(rhs.getGradeToSign());
		this->setGradeToExec(rhs.getGradeToExec());
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm const &rhs)
{
	o << "PresidentialPardonForm:" << std::endl
	<< "\t" "name: " << rhs.getName() << std::endl
	<< "\t" "isSigned: " << (rhs.getIsSigned() ? "true" : "false") << std::endl
	<< "\t" "gradeToSign: " << rhs.getGradeToSign() << std::endl
	<< "\t" "gradeToExec: " << rhs.getGradeToExec() << std::endl
	<< "\t" "target: " << rhs.getTarget() << std::endl;
	return o;
}
