/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:35:26 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/01 17:37:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "class/AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string const	_target;

protected:

public:
	// Constructors
	PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	PresidentialPardonForm(std::string const &target);

	// Destructors
	virtual ~PresidentialPardonForm(void);

	// Accessors
	std::string const	&getTarget(void) const;

	// Member functions
	virtual void	beSigned(Bureaucrat const &b);
	virtual void	execute(Bureaucrat const &b) const;

	// Operator overloads
	PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);
};

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm const &rhs);

#endif
