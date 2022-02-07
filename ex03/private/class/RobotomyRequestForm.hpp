/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:35:06 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/07 03:50:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "class/AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string const	_target;

protected:

public:
	// Constructors
	RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	RobotomyRequestForm(std::string const &target);

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
