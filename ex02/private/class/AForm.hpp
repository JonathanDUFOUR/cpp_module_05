/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 21:11:45 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/22 22:04:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "class/Bureaucrat.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

class Bureaucrat;

class AForm
{
private:
	// Attributes
	std::string const	_name;
	bool				_isSigned;
	int const			_gradeToSign;
	int const			_gradeToExec;

protected:
	class GradeTooHighException : public std::exception
	{
	private:
		// Member functions
		virtual char const	*what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
	private:
		// Member functions
		virtual char const	*what(void) const throw();
	};

	class AlreadySignedException : public std::exception
	{
	private:
		// Member functions
		virtual char const	*what(void) const throw();
	};

	// Constructors
	AForm(
		std::string const &name = std::string("defaultName"),
		bool const issigned = false,
		int const gradeToSign = 150,
		int const gradeToExec = 150);
	AForm(AForm const &src);

public:
	// Destructors
	virtual ~AForm(void);

	// Accessors
	std::string const	&getName(void) const;
	bool const			&getIsSigned(void) const;
	int const			&getGradeToSign(void) const;
	int const			&getGradeToExec(void) const;

	void				setIsSigned(bool const issigned);

	// Member functions
	virtual void	beSigned(Bureaucrat const &b) = 0;
	virtual void	execute(Bureaucrat const &b) const = 0;

	// Operators
	AForm	&operator=(AForm const &rhs);
};

std::ostream	&operator<<(std::ostream &o, AForm const &rhs);

#endif
