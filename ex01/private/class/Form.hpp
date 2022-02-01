/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 21:11:45 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/31 23:20:50 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "class/Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	// Attributes
	std::string const	_name;
	bool				_isSigned;
	int const			_gradeToSign;
	int const			_gradeToExec;

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

protected:

public:
	// Constructors
	Form(void);
	Form(Form const &src);
	Form(
		std::string const name,
		bool const issigned,
		int const gradeToSign,
		int const gradeToExec);

	// Destructors
	virtual ~Form(void);

	// Accessors
	std::string const	&getName(void) const;

	bool const			&getIsSigned(void) const;

	int const			&getGradeToSign(void) const;
	int const			&getGradeToExec(void) const;

	// Member functions
	void	beSigned(Bureaucrat const &b);

	// Operator overloads
	Form	&operator=(Form const &rhs);
};

std::ostream	&operator<<(std::ostream &o, Form const &rhs);

#endif
