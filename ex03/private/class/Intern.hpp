/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:48:57 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/01 22:13:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "class/AForm.hpp"

class AForm;

class Intern
{
private:

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
