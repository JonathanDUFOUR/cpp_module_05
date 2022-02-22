/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:34:22 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/22 21:59:14 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "class/AForm.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

class ShrubberyCreationForm : public AForm
{
private:
	// Attributes
	std::string	_target;

protected:

public:
	// Constructors
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	ShrubberyCreationForm(std::string const &target);

	// Destructors
	virtual ~ShrubberyCreationForm(void);

	// Accessors
	std::string const	&getTarget(void) const;

	// Member functions
	virtual void	beSigned(Bureaucrat const &b);
	virtual void	execute(Bureaucrat const &b) const;

	// Operators
	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);
};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm const &rhs);

#endif
