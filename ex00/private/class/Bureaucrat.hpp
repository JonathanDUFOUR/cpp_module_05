/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:47:48 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/30 19:24:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
private:
	int					_grade;
	std::string const	_name;

protected:

public:
	// Constructors
	Bureaucrat(void);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat(int const grade, std::string const name);

	// Destructors
	virtual ~Bureaucrat(void);

	// Accessors
	int const			&getGrade(void) const;

	std::string const	&getName(void) const;

	// Member functions
	void	decrementGrade(void);
	void	incrementGrade(void);

	// Operator overloads
	Bureaucrat	&operator=(Bureaucrat const &rhs);
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
