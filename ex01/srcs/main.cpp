/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:47:08 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/22 16:43:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "class/Bureaucrat.hpp"

static void	__test0(void)
{
	try
	{
		Form	f("ation", false, 50, 25);

		std::cout << f << std::endl;
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
		Form	f("alin", false, 256, 42);

		std::cout << f << std::endl;
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
		Form	f("ulaire", false, 21, 0);

		std::cout << f << std::endl;
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
		Bureaucrat	b("Charlie", 42);
		Form		f("at", false, 42, 21);

		std::cout << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);
	}
	catch (std::exception const &e)
	{
		std::cerr
		<< "Error: "
		<< e.what()
		<< std::endl;
	}
}

static void	__test4(void)
{
	try
	{
		Bureaucrat	b("Ben", 55);
		Form		f("ula 1", false, 54, 21);

		std::cout << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);
	}
	catch (std::exception const &e)
	{
		std::cerr
		<< "Error: "
		<< e.what()
		<< std::endl;
	}
}

static void	__test5(void)
{
	try
	{
		Bureaucrat	b("Melissa", 1);
		Form		f("idable", true, 42, 24);

		std::cout << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);
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
	std::cout << "-----------------------------------------------" << std::endl;
	__test4();
	std::cout << "-----------------------------------------------" << std::endl;
	__test5();
	return EXIT_SUCCESS;
}
