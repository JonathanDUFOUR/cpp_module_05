/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:31:29 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/01 19:49:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "class/RobotomyRequestForm.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("robotomy request", false, 72, 45),
	_target("defaultTarget")
{
	std::cout
	<< "Writing RobotomyRequestForm "
	<< this->getName()
	<< " (" << this->getGradeToSign() << ")"
	<< " (" << this->getGradeToExec() << ")"
	<< " -> " << this->_target
	<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
	AForm(src.getName(), src.getIsSigned(), src.getGradeToSign(), src.getGradeToExec()),
	_target(src._target)
{
	std::cout
	<< "Writing RobotomyRequestForm "
	<< this->getName()
	<< " (" << this->getGradeToSign() << ")"
	<< " (" << this->getGradeToExec() << ")"
	<< " -> " << this->_target
	<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
	AForm("robotomy request", false, 72, 45),
	_target(target)
{
	std::cout
	<< "Writing RobotomyRequestForm "
	<< this->getName()
	<< " (" << this->getGradeToSign() << ")"
	<< " (" << this->getGradeToExec() << ")"
	<< " -> " << this->_target
	<< std::endl;
}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout
	<< "Burning RobotomyRequestForm "
	<< this->getName()
	<< std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

std::string const	&RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

void	RobotomyRequestForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	if (this->getIsSigned())
		throw AForm::AlreadySignedException();
	this->setIsSigned(true);
}

void	RobotomyRequestForm::execute(Bureaucrat const &b) const
{
	if (b.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	std::cout
	<< "** drilling noises **"
	<< std::endl;
	if (std::rand() % 2)
		std::cout
		<< this->_target
		<< " has been robotomized successfuly!"
		<< std::endl;
	else
		std::cout
		<< "The robotomy of "
		<< this->_target
		<< " failed..."
		<< std::endl;
}

// ************************************************************************** //
//                             Operator Overloads                             //
// ************************************************************************** //

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
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

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &rhs)
{
	o << "RobotomyRequestForm:" << std::endl
	<< "\t" "name: " << rhs.getName() << std::endl
	<< "\t" "isSigned: " << (rhs.getIsSigned() ? "true" : "false") << std::endl
	<< "\t" "gradeToSign: " << rhs.getGradeToSign() << std::endl
	<< "\t" "gradeToExec: " << rhs.getGradeToExec() << std::endl
	<< "\t" "target: " << rhs.getTarget() << std::endl;
	return o;
}
