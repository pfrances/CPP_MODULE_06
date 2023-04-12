/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:48:13 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/12 22:32:20 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

#define FORM_NAME_ "RobotomyRequestForm"

RobotomyRequestForm::RobotomyRequestForm( void ) : Form(FORM_NAME_, GRADE_TO_SIGN_, GRADE_TO_EXECUTE_), Target_("default") {
	std::cout << "[RobotomyRequestForm] default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string Target ) : Form(FORM_NAME_, GRADE_TO_SIGN_, GRADE_TO_EXECUTE_), Target_(Target) {
	std::cout << "[RobotomyRequestForm] typed constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :	Form(other), Target_(other.getTarget()) {
	std::cout << "[RobotomyRequestForm] copy constructor called." << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		Form::operator=(other);
		this->Target_ = other.getTarget();
	}
	std::cout << "[RobotomyRequestForm] asignment called." << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	std::cout << "[RobotomyRequestForm] destructor called." << std::endl;
}

const std::string& RobotomyRequestForm::getTarget( void ) const {
	return this->Target_;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (this->checkRequirement(executor)) {
		std::cout << "* drilling noise * " << std::endl;
		int rand_nb = rand() % 2;
		if (rand_nb) {
			std::cout << this->Target_ << " was successfully robotomized!" << std::endl;
		} else {
			std::cout << this->Target_ << "'s robotomy has failed!" << std::endl;
		}
	}
}
