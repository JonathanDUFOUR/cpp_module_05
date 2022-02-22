/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:35:06 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/22 21:59:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "class/AForm.hpp"

# ifndef DEBUG
#  define DEBUG 0
# endif

class RobotomyRequestForm : public AForm
{
private:
	// Attributes
	std::string	_target;

public:
	// Constructors
	RobotomyRequestForm(
		std::string const &target = std::string("defaultTarget"));
	RobotomyRequestForm(RobotomyRequestForm const &src);

	// Destructors
	virtual ~RobotomyRequestForm(void);

	// Accessors
	std::string const	&getTarget(void) const;

	// Member functions
	virtual void	beSigned(Bureaucrat const &b);
	virtual void	execute(Bureaucrat const &b) const;

	// Operators
	RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);
};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &rhs);

#endif
