/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:47:48 by jodufour          #+#    #+#             */
/*   Updated: 2022/03/02 20:02:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "class/AForm.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

typedef unsigned int	uint;

class AForm;

class Bureaucrat
{
private:
	// Attributes
	std::string const	_name;
	uint				_grade;

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
	Bureaucrat(
		std::string const &name = std::string("defaultName"),
		uint const grade = 150U);
	Bureaucrat(Bureaucrat const &src);

	// Destructors
	virtual ~Bureaucrat(void);

	// Accessors
	std::string const	&getName(void) const;
	uint const			&getGrade(void) const;

	// Member functions
	void	decrementGrade(void);
	void	incrementGrade(void);
	void	signForm(AForm &f) const;
	void	executeForm(AForm const &f) const;

	// Operators
	Bureaucrat	&operator=(Bureaucrat const &rhs);
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
