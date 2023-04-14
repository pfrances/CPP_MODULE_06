/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:31:20 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/14 12:00:56 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#define FORM_NAME "PresidentialPardonForm"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm(FORM_NAME, GRADE_TO_SIGN_, GRADE_TO_EXECUTE_), Target_("default") {
	std::cout << "[PresidentialPardonForm] default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string Target ) : AForm(FORM_NAME, GRADE_TO_SIGN_, GRADE_TO_EXECUTE_), Target_(Target) {
	std::cout << "[PresidentialPardonForm] typed constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), Target_(other.getTarget()) {
	std::cout << "[PresidentialPardonForm] copy constructor called." << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->Target_ = other.getTarget();
	}
	std::cout << "[PresidentialPardonForm] asignment called." << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	std::cout << "[PresidentialPardonForm] destructor called." << std::endl;
}

const std::string& PresidentialPardonForm::getTarget( void ) const {
	return this->Target_;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (this->checkRequirement(executor)) {
		std::cout << this->Target_ << " was forgiven by Zaphod Beeblebrox." << std::endl;
	}
}
