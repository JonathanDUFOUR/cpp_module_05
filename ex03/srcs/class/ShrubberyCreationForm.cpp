/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:33:37 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/22 21:40:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "class/ShrubberyCreationForm.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
	AForm("shrubbery creation", false, 145, 137),
	_target(target)
{
	if (DEBUG)
		std::cout
		<< "Creating ShrubberyCreationForm "
		<< this->getName()
		<< " (" << this->getGradeToSign() << ")"
		<< " (" << this->getGradeToExec() << ")"
		<< " (" << this->_target << ")"
		<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
	AForm(src),
	_target(src._target)
{
	if (DEBUG)
		std::cout
		<< "Creating ShrubberyCreationForm "
		<< this->getName()
		<< " (" << this->getGradeToSign() << ")"
		<< " (" << this->getGradeToExec() << ")"
		<< " (" << this->_target << ")"
		<< std::endl;
}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (DEBUG)
		std::cout
		<< "Destroying ShrubberyCreationForm "
		<< this->getName()
		<< std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

std::string const	&ShrubberyCreationForm::getTarget(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling ShrubberyCreationForm::getTarget()"
		<< std::endl;
	return this->_target;
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

void	ShrubberyCreationForm::beSigned(Bureaucrat const &b)
{
	if (DEBUG)
		std::cout
		<< "Calling ShrubberyCreationForm::beSigned()"
		<< std::endl;
	if (b.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	if (this->getIsSigned())
		throw AForm::AlreadySignedException();
	this->setIsSigned(true);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &b) const
{
	std::ofstream		ofs;
	std::string const	filename = this->_target + "_shrubbery";

	if (DEBUG)
		std::cout
		<< "Calling ShrubberyCreationForm::execute()"
		<< std::endl;
	if (b.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	ofs.open(filename.c_str());
	// ofs << "ASCII trees" << std::endl;
	ofs << "\
            .        +          .      .          .\n\
     .            _        .                    .\n\
  ,              /;-._,-.____        ,-----.__\n\
 ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n\
  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n\
                      ,    `./  \\:. `.   )==-'  .\n\
    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n\
.           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n\
       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n\
  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n\
   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n\
              \\:  `  X` _| _,\\/'   .-'\n\
.               \":._:`\\____  /:'  /      .           .\n\
                    \\::.  :\\/:'  /              +\n\
   .                 `.:.  /:'  }      .\n\
           .           ):_(:;   \\           .\n\
                      /:. _/ ,  |\n\
                   . (|::.     ,`                  .\n\
     .                |::.    {\\\n\
                      |::.\\  \\ `.\n\
                      |:::(\\    |\n\
              O       |:::/{ }  |                  (o\n\
               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n\
          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n\
      ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~"
	<< std::endl;
	ofs.close();
}

// ************************************************************************* //
//                                 Operators                                 //
// ************************************************************************* //

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (DEBUG)
		std::cout
		<< "Calling ShrubberyCreationForm::operator=()"
		<< std::endl;
	if (this != &rhs)
	{
		this->AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm const &rhs)
{
	o << "ShrubberyCreationForm:" << std::boolalpha << std::endl
	<< "\t" "name: " << rhs.getName() << std::endl
	<< "\t" "isSigned: " << rhs.getIsSigned() << std::endl
	<< "\t" "gradeToSign: " << rhs.getGradeToSign() << std::endl
	<< "\t" "gradeToExec: " << rhs.getGradeToExec() << std::endl
	<< "\t" "target: " << rhs.getTarget() << std::endl;
	return o;
}
