/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 21:11:45 by jodufour          #+#    #+#             */
/*   Updated: 2022/03/02 20:00:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "class/Bureaucrat.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

typedef unsigned int	uint;

class Bureaucrat;

class AForm
{
private:
	// Attributes
	std::string const	_name;
	bool				_isSigned;
	uint const			_gradeToSign;
	uint const			_gradeToExec;

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
		uint const gradeToSign = 150U,
		uint const gradeToExec = 150U);
	AForm(AForm const &src);

public:
	// Destructors
	virtual ~AForm(void);

	// Accessors
	std::string const	&getName(void) const;
	bool const			&getIsSigned(void) const;
	uint const			&getGradeToSign(void) const;
	uint const			&getGradeToExec(void) const;

	void				setIsSigned(bool const issigned);

	// Member functions
	virtual void	beSigned(Bureaucrat const &b) = 0;
	virtual void	execute(Bureaucrat const &b) const = 0;

	// Operators
	AForm	&operator=(AForm const &rhs);
};

std::ostream	&operator<<(std::ostream &o, AForm const &rhs);

#endif
