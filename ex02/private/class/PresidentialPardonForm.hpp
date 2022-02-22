/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:35:26 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/22 21:58:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "class/AForm.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

class PresidentialPardonForm : public AForm
{
private:
	// Attributes
	std::string	_target;

public:
	// Constructors
	PresidentialPardonForm(
		std::string const &target = std::string("defaultTarget"));
	PresidentialPardonForm(PresidentialPardonForm const &src);

	// Destructors
	virtual ~PresidentialPardonForm(void);

	// Accessors
	std::string const	&getTarget(void) const;

	// Member functions
	virtual void	beSigned(Bureaucrat const &b);
	virtual void	execute(Bureaucrat const &b) const;

	// Operators
	PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);
};

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm const &rhs);

#endif
