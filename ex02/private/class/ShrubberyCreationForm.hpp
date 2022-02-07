/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:34:22 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/07 03:50:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "class/AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string const	_target;

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
