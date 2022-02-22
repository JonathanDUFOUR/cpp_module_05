/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:31:29 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/22 21:41:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "class/RobotomyRequestForm.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
	AForm("robotomy request", false, 72, 45),
	_target(target)
{
	if (DEBUG)
		std::cout
		<< "Creating RobotomyRequestForm "
		<< this->getName()
		<< " (" << this->getGradeToSign() << ")"
		<< " (" << this->getGradeToExec() << ")"
		<< " (" << this->_target << ")"
		<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
	AForm(src),
	_target(src._target)
{
	if (DEBUG)
		std::cout
		<< "Creating RobotomyRequestForm "
		<< this->getName()
		<< " (" << this->getGradeToSign() << ")"
		<< " (" << this->getGradeToExec() << ")"
		<< " (" << this->_target << ")"
		<< std::endl;
}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (DEBUG)
		std::cout
		<< "Destroying RobotomyRequestForm "
		<< this->getName()
		<< std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

std::string const	&RobotomyRequestForm::getTarget(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling RobotomyRequestForm::getTarget()"
		<< std::endl;
	return this->_target;
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

void	RobotomyRequestForm::beSigned(Bureaucrat const &b)
{
	if (DEBUG)
		std::cout
		<< "Calling RobotomyRequestForm::beSigned()"
		<< std::endl;
	if (b.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	if (this->getIsSigned())
		throw AForm::AlreadySignedException();
	this->setIsSigned(true);
}

void	RobotomyRequestForm::execute(Bureaucrat const &b) const
{
	if (DEBUG)
		std::cout
		<< "Calling RobotomyRequestForm::execute()"
		<< std::endl;
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

// ************************************************************************* //
//                                 Operators                                 //
// ************************************************************************* //

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (DEBUG)
		std::cout
		<< "Calling RobotomyRequestForm::operator=()"
		<< std::endl;
	if (this != &rhs)
	{
		this->AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &rhs)
{
	o << "RobotomyRequestForm:" << std::boolalpha << std::endl
	<< "\t" "name: " << rhs.getName() << std::endl
	<< "\t" "isSigned: " << rhs.getIsSigned() << std::endl
	<< "\t" "gradeToSign: " << rhs.getGradeToSign() << std::endl
	<< "\t" "gradeToExec: " << rhs.getGradeToExec() << std::endl
	<< "\t" "target: " << rhs.getTarget() << std::endl;
	return o;
}
