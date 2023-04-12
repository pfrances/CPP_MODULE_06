/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:38:04 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/12 12:06:46 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
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

	Form f1("f1", 1, 1);

	b2.signForm(f1);
	b1.signForm(f1);
	b1.signForm(f1);

	std::cout << std::endl;

	return 0;
}
