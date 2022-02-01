/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:47:48 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/31 23:57:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "class/Form.hpp"

class Form;

class Bureaucrat
{
private:
	// Attributes
	std::string const	_name;
	int					_grade;

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

public:
	// Constructors
	Bureaucrat(void);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat(std::string const name, int const grade);

	// Destructors
	virtual ~Bureaucrat(void);

	// Accessors
	std::string const	&getName(void) const;

	int const			&getGrade(void) const;

	// Member functions
	void	decrementGrade(void);
	void	incrementGrade(void);
	void	signForm(Form &f) const;

	// Operator overloads
	Bureaucrat	&operator=(Bureaucrat const &rhs);
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
