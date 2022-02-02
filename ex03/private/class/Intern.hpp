/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:48:57 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/02 15:18:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <signal.h>
# include "class/AForm.hpp"

typedef struct s_nameForm	t_nameForm;
typedef AForm *				(*t_fct)(std::string const &target);

struct s_nameForm
{
	std::string const	name;
	t_fct const			maker;
};

class AForm;

class Intern
{
private:
	// Attributes
	static t_nameForm	lookup[];

	class UnknownFormException : public std::exception
	{
	private:
		// Member functions
		virtual char const	*what(void) const throw();
	};

	// Member functions
	static AForm	*makeShrubberyCreationForm(std::string const &target);
	static AForm	*makeRobotomyRequestForm(std::string const &target);
	static AForm	*makePresidentialPardonForm(std::string const &target);

protected:

public:
	// Constructors
	Intern(void);
	Intern(Intern const &src);

	// Destructors
	virtual ~Intern(void);

	// Member functions
	AForm	*makeForm(std::string const &name, std::string const &target) const;

	// Operator overloads
	Intern	&operator=(Intern const &rhs);
};

std::ostream	&operator<<(std::ostream &o, Intern const &rhs);

#endif
