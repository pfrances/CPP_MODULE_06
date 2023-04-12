/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:31:20 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/12 15:59:06 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#define FORM_NAME_ "PresidentialPardonForm"

PresidentialPardonForm::PresidentialPardonForm( void ) : Form(FORM_NAME_, GRADE_TO_SIGN_, GRADE_TO_EXECUTE_), Target_("default") {
	std::cout << "[PresidentialPardonForm] default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string Target ) : Form(FORM_NAME_, GRADE_TO_SIGN_, GRADE_TO_EXECUTE_), Target_(Target) {
	std::cout << "[PresidentialPardonForm] typed constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :	Form(other), Target_(other.getTarget()) {
	std::cout << "[PresidentialPardonForm] copy constructor called." << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		Form::operator=(other);
		this->Target_ = other.getTarget();
	}
	std::cout << "[PresidentialPardonForm] asignment called." << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	std::cout << "[PresidentialPardonForm] destructor called." << std::endl;
}

std::string PresidentialPardonForm::getTarget( void ) const {
	return this->Target_;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (this->checkRequirement(executor)) {
		std::cout << executor << " was forgiven by Zaphod Beeblebrox." << std::endl;
	}
}