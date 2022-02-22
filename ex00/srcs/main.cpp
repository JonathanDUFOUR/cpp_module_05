/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:47:08 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/22 16:26:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "class/Bureaucrat.hpp"

static void	__test0(void)
{
	try
	{
		Bureaucrat	b("Charlie", 149);

		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception const &e)
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
		Bureaucrat	b("Ben", 2);

		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception const &e)
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
		Bureaucrat	b("Alexandra", 2147483647);

		std::cout << b << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr
		<< "Error: "
		<< e.what()
		<< std::endl;
	}
}

static void	__test3(void)
{
	try
	{
		Bureaucrat	b("Melissa", -2147483648);

		std::cout << b << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr
		<< "Error: "
		<< e.what()
		<< std::endl;
	}
}

int	main(void)
{
	__test0();
	std::cout << "-----------------------------------------------" << std::endl;
	__test1();
	std::cout << "-----------------------------------------------" << std::endl;
	__test2();
	std::cout << "-----------------------------------------------" << std::endl;
	__test3();

	return EXIT_SUCCESS;
}
