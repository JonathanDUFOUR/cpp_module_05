/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:47:08 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/01 22:13:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "class/Intern.hpp"

static void	__test0(void)
{
	try
	{

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
