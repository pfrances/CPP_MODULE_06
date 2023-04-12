/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:38:04 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/12 15:36:08 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void	update_grade(Bureaucrat& b, void (Bureaucrat::*func)(void)) {
	try {
		(b.*func)();
	} catch(const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "GradeTooHighException catched: " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "GradeTooLowException catched: " << e.what() << std::endl;
	}
	std::cout << b << std::endl;
}

void	TryToExecute(Form& f, Bureaucrat& b) {
	try {
		std::cout << b << " Try to execute " << f.getName() << std::endl;
		b.executeForm(f);
		std::cout << b << " was able to execute " << f.getName() << std::endl;
	} catch(std::exception& e) {
		std::cout << b << " has failed to execute " << f.getName() << std::endl;
	}
	std::cout << std::endl;
}


int	main(void) {
	Bureaucrat b1("b1", 1);
	std::cout << b1 << std::endl;
	update_grade(b1, &Bureaucrat::decrementGrade);
	update_grade(b1, &Bureaucrat::incrementGrade);
	update_grade(b1, &Bureaucrat::incrementGrade);

	Bureaucrat b2("b2", 150);
	std::cout << b2 << std::endl;
	update_grade(b2, &Bureaucrat::decrementGrade);

	std::cout << std::endl;

	ShrubberyCreationForm f1("Garden");

	b2.signForm(f1);
	b1.signForm(f1);
	b1.signForm(f1);

	std::cout << std::endl;

	TryToExecute(f1, b2);
	TryToExecute(f1, b1);

	RobotomyRequestForm f2("Kevin");

	b2.signForm(f2);
	b1.signForm(f2);
	b1.signForm(f2);

	std::cout << std::endl;

	TryToExecute(f2, b2);
	TryToExecute(f2, b1);

	PresidentialPardonForm f3("John");

	b2.signForm(f3);
	b1.signForm(f3);
	b1.signForm(f3);

	std::cout << std::endl;

	TryToExecute(f3, b2);
	TryToExecute(f3, b1);

	return 0;
}
