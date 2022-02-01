/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 21:11:45 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/01 17:19:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "class/Bureaucrat.hpp"

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

public:
	// Constructors
	AForm(void);
	AForm(AForm const &src);
	AForm(
		std::string const name,
		bool const issigned,
		int const gradeToSign,
		int const gradeToExec);

	// Destructors
	virtual ~AForm(void);

	// Accessors
	std::string const	&getName(void) const;
	bool const			&getIsSigned(void) const;
	int const			&getGradeToSign(void) const;
	int const			&getGradeToExec(void) const;

	void				setName(std::string const &name);
	void				setIsSigned(bool const isSigned);
	void				setGradeToSign(int const gradeToSign);
	void				setGradeToExec(int const gradeToExec);

	// Member functions
	virtual void	beSigned(Bureaucrat const &b) = 0;
	virtual void	execute(Bureaucrat const &b) const = 0;

	// Operator overloads
	AForm	&operator=(AForm const &rhs);
};

std::ostream	&operator<<(std::ostream &o, AForm const &rhs);

#endif
