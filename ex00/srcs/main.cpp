/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:47:08 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/01 00:33:29 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "class/Bureaucrat.hpp"

static void	__test0(void)
{
	try
	{
		Bureaucrat	b0("Charlie", 149);

		std::cout << b0 << std::endl;
		b0.decrementGrade();
		std::cout << b0 << std::endl;
		b0.decrementGrade();
		std::cout << b0 << std::endl;
	}
	catch (std::exception &e)
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
		Bureaucrat	b1("Ben", 2);

		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
	}
	catch (std::exception &e)
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
		Bureaucrat	b2("Alexandra", 2147483647);

		std::cout << b2 << std::endl;
	}
	catch (std::exception &e)
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
		Bureaucrat	b3("Melissa", -2147483648);

		std::cout << b3 << std::endl;
	}
	catch (std::exception &e)
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
	std::cout << "===============================================" << std::endl;
	__test1();
	std::cout << "===============================================" << std::endl;
	__test2();
	std::cout << "===============================================" << std::endl;
	__test3();

	return EXIT_SUCCESS;
}
