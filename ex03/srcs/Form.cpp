/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:57:59 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/12 16:52:09 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) :	Name_("Default name"),
						GradeToSign_(LOWEST_GRADE_),
						GradeToExecute_(LOWEST_GRADE_),
						IsSigned_(false) {
	std::cout << "[Form] default constructor called." << std::endl;
}

Form::Form( std::string Name, int GradeToSign, int GradeToExecute ) :	Name_(Name),
																		GradeToSign_(GradeToSign),
																		GradeToExecute_(GradeToExecute),
																		IsSigned_(false) {
	if (this->GradeToSign_ < HIGHEST_GRADE_)
		this->GradeToSign_ = HIGHEST_GRADE_;
	else if (this->GradeToSign_ > LOWEST_GRADE_)
		this->GradeToSign_ = LOWEST_GRADE_;
	if (this->GradeToExecute_ < HIGHEST_GRADE_)
		this->GradeToExecute_ = HIGHEST_GRADE_;
	else if (this->GradeToExecute_ > LOWEST_GRADE_)
		this->GradeToExecute_ = LOWEST_GRADE_;
	std::cout << "[Form] typed constructor called." << std::endl;
}

Form::Form(const Form& other) :	Name_(other.getName()),
								GradeToSign_(other.getGradeToSign()),
								GradeToExecute_(other.getGradeToExecute()),
								IsSigned_(other.getSignState()) {
	std::cout << "[Form] copy constructor called." << std::endl;
}

Form&	Form::operator=(const Form& other) {
	if (this != &other) {
		this->GradeToSign_ = other.getGradeToSign();
		this->GradeToExecute_ = other.getGradeToExecute();
		this->IsSigned_ = other.getSignState();
	}
	std::cout << "[Form] asignment called." << std::endl;
	return *this;
}

Form::~Form( void ) {
	std::cout << "[Form] destructor called." << std::endl;
}

std::string Form::getName( void ) const throw() {
	return this->Name_;
}

int Form::getGradeToSign( void ) const throw() {
	return this->GradeToSign_;
}

int Form::getGradeToExecute( void ) const throw() {
	return this->GradeToExecute_;
}

bool Form::getSignState( void ) const throw() {
	return this->IsSigned_;
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* Form::IsAlreadySignedException::what() const throw() {
	return "This form is already signed";
}

const char* Form::IsNotSignedException::what() const throw() {
	return "This form isn't already signed";
}

void Form::beSigned(Bureaucrat const & b) {
	if (this->IsSigned_ == true) {
		throw IsAlreadySignedException();
	} else if (b.getGrade() <= this->GradeToSign_) {
		this->IsSigned_ = true;
	} else {
		throw GradeTooLowException();
	}
}

bool	Form::checkRequirement(Bureaucrat const & b) const {
	if (this->getSignState() == false) {
		throw IsNotSignedException();
	} else if (b.getGrade() > this->GradeToExecute_) {
		throw GradeTooLowException();
	} else {
		return true;
	}
	return false;
}
