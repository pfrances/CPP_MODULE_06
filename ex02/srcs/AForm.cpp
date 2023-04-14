/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:55:23 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/14 11:59:41 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm( void ) :	Name_("Default name"),
						GradeToSign_(LOWEST_GRADE_),
						GradeToExecute_(LOWEST_GRADE_),
						IsSigned_(false) {
	std::cout << "[Form] default constructor called." << std::endl;
}

AForm::AForm( const std::string Name, const int GradeToSign, const int GradeToExecute ) :	Name_(Name),
																		GradeToSign_(GradeToSign),
																		GradeToExecute_(GradeToExecute),
																		IsSigned_(false) {
	if (this->GradeToSign_ < HIGHEST_GRADE_)
		throw AForm::GradeTooHighException();
	else if (this->GradeToSign_ > LOWEST_GRADE_)
		throw AForm::GradeTooLowException();
	if (this->GradeToExecute_ < HIGHEST_GRADE_)
		throw AForm::GradeTooHighException();
	else if (this->GradeToExecute_ > LOWEST_GRADE_)
		throw AForm::GradeTooLowException();
	std::cout << "[Form] typed constructor called." << std::endl;
}

AForm::AForm(const AForm& other) :	Name_(other.getName()),
								GradeToSign_(other.getGradeToSign()),
								GradeToExecute_(other.getGradeToExecute()),
								IsSigned_(other.getSignState()) {
	std::cout << "[Form] copy constructor called." << std::endl;
}

AForm&	AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->IsSigned_ = other.getSignState();
	}
	std::cout << "[Form] asignment called." << std::endl;
	return *this;
}

AForm::~AForm( void ) {
	std::cout << "[Form] destructor called." << std::endl;
}

const std::string& AForm::getName( void ) const {
	return this->Name_;
}

int AForm::getGradeToSign( void ) const {
	return this->GradeToSign_;
}

int AForm::getGradeToExecute( void ) const {
	return this->GradeToExecute_;
}

bool AForm::getSignState( void ) const {
	return this->IsSigned_;
}

const char* AForm::GradeTooLowException::what( void ) const throw() {
	return "Grade is too low";
}

const char* AForm::GradeTooHighException::what( void ) const throw() {
	return "Grade is too high";
}

const char* AForm::IsAlreadySignedException::what( void ) const throw() {
	return "This form is already signed";
}

const char* AForm::IsNotSignedException::what( void ) const throw() {
	return "This form isn't already signed";
}

void AForm::beSigned(const Bureaucrat& b) {
	if (this->IsSigned_ == true) {
		throw IsAlreadySignedException();
	} else if (b.getGrade() <= this->GradeToSign_) {
		this->IsSigned_ = true;
	} else {
		throw GradeTooLowException();
	}
}

bool	AForm::checkRequirement(const Bureaucrat& b) const {
	if (this->getSignState() == false) {
		throw IsNotSignedException();
	} else if (b.getGrade() > this->GradeToExecute_) {
		throw GradeTooLowException();
	}
	return true;
}

std::ostream& operator<<(std::ostream& stream, const AForm& f) {
	stream	<< f.getName()
			<< " could be signed with a minimum grade of " << f.getGradeToSign()
			<< " and execute with a minimum grade of " << f.getGradeToExecute()
			<< (f.getSignState() ? " and is already signed" : " and is not already signed");
	return stream;
}
