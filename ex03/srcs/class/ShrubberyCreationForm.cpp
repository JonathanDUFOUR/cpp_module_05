/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:33:37 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/01 21:57:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "class/ShrubberyCreationForm.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("shrubbery creation", false, 145, 137),
	_target("defaultTarget")
{
	std::cout
	<< "Writing ShrubberyCreationForm "
	<< this->getName()
	<< " (" << this->getGradeToSign() << ")"
	<< " (" << this->getGradeToExec() << ")"
	<< " -> " << this->_target
	<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
	AForm(src.getName(), src.getIsSigned(), src.getGradeToSign(), src.getGradeToExec()),
	_target(src._target)
{
	std::cout
	<< "Writing ShrubberyCreationForm "
	<< this->getName()
	<< " (" << this->getGradeToSign() << ")"
	<< " (" << this->getGradeToExec() << ")"
	<< " -> " << this->_target
	<< std::endl;
	*this = src;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
	AForm("shrubbery creation", false, 145, 137),
	_target(target)
{
	std::cout
	<< "Writing ShrubberyCreationForm "
	<< this->getName()
	<< " (" << this->getGradeToSign() << ")"
	<< " (" << this->getGradeToExec() << ")"
	<< " -> " << this->_target
	<< std::endl;
}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout
	<< "Burning ShrubberyCreationForm "
	<< this->getName()
	<< std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

std::string const	&ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

void	ShrubberyCreationForm::beSigned(Bureaucrat const &b)
{
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

// ************************************************************************** //
//                             Operator Overloads                             //
// ************************************************************************** //

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
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

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm const &rhs)
{
	o << "ShrubberyCreationForm:" << std::endl
	<< "\t" "name: " << rhs.getName() << std::endl
	<< "\t" "isSigned: " << (rhs.getIsSigned() ? "true" : "false") << std::endl
	<< "\t" "gradeToSign: " << rhs.getGradeToSign() << std::endl
	<< "\t" "gradeToExec: " << rhs.getGradeToExec() << std::endl
	<< "\t" "target: " << rhs.getTarget() << std::endl;
	return o;
}
