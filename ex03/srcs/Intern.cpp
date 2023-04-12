/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:55:33 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/12 22:40:18 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern( void ) {
	std::cout << "[Intern] default constructor called." << std::endl;
}

Intern::Intern(const Intern& other) {
	(void)other;
	std::cout << "[Intern] copy constructor called." << std::endl;
}

Intern&	Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
	std::cout << "[Intern] asignment called." << std::endl;
}

Intern::~Intern( void ) {
	std::cout << "[Intern] destructor called." << std::endl;
}

Form* Intern::makeForm(const std::string Form_Name, const std::string Target) const {

	Form		*Form = NULL;
	std::string	FormNamesArr[3] = {"shrubberry creation", "robotomy request", "presidential pardon"};
	size_t		i;

	for (i = 0; i < (sizeof(FormNamesArr) / sizeof(std::string)); i++) {
		if (FormNamesArr[i] == Form_Name)
			break;
	}
	switch (i)
	{
		case 0:
			Form = new ShrubberyCreationForm(Target);
			break;
		case 1:
			Form =  new RobotomyRequestForm(Target);
			break;
		case 2:
			Form = new PresidentialPardonForm(Target);
			break;
		default:
			std::cerr << "invalid form name. Please choose from the list below:" << std::endl;
			std::cerr << "	shrubberry creation" << std::endl;
			std::cerr << "	robotomy request" << std::endl;
			std::cerr << "	presidential pardon" << std::endl;
			break;
	}
	if (Form != NULL)
		std::cout << "Intern creates " << Form->getName() << std::endl;
	return Form;
}
