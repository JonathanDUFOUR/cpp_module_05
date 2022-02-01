/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:47:08 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/01 20:38:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "class/Bureaucrat.hpp"
#include "class/ShrubberyCreationForm.hpp"
#include "class/RobotomyRequestForm.hpp"
#include "class/PresidentialPardonForm.hpp"

static void	__test0(void)
{
	try
	{
		Bureaucrat				b("Delphine", 137);
		ShrubberyCreationForm	f("FoodTruck");

		std::cout << b << std::endl;
		std::cout << f << std::endl;

		b.signForm(f);
		b.executeForm(f);
	}
	catch(const std::exception &e)
	{
		std::cerr
		<< "Error: "
		<< e.what()
		<< std::endl;
	}
}

static void	__test1(void)
{
	try
	{
		Bureaucrat			b("Melissa", 1);
		RobotomyRequestForm	f("Hoodie");

		std::cout << b << std::endl;
		std::cout << f << std::endl;

		b.signForm(f);
		b.executeForm(f);
	}
	catch(const std::exception &e)
	{
		std::cerr
		<< "Error: "
		<< e.what()
		<< std::endl;
	}
}

static void	__test2(void)
{
	try
	{
		Bureaucrat				b("Bibiche", 2);
		PresidentialPardonForm	f("Reach");

		std::cout << b << std::endl;
		std::cout << f << std::endl;

		b.signForm(f);
		b.executeForm(f);
	}
	catch(const std::exception &e)
	{
		std::cerr
		<< "Error: "
		<< e.what()
		<< std::endl;
	}
}

int	main(void)
{
	std::srand(time(NULL));
	__test0();
	std::cout << "===============================================" << std::endl;
	__test1();
	std::cout << "===============================================" << std::endl;
	__test2();
	return EXIT_SUCCESS;
}
