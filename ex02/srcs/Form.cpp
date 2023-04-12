/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:57:59 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/12 22:31:20 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

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
		throw Form::GradeTooHighException();
	else if (this->GradeToSign_ > LOWEST_GRADE_)
		throw Form::GradeTooLowException();
	if (this->GradeToExecute_ < HIGHEST_GRADE_)
		throw Form::GradeTooHighException();
	else if (this->GradeToExecute_ > LOWEST_GRADE_)
		throw Form::GradeTooLowException();
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
		this->IsSigned_ = other.getSignState();
	}
	std::cout << "[Form] asignment called." << std::endl;
	return *this;
}

Form::~Form( void ) {
	std::cout << "[Form] destructor called." << std::endl;
}

const std::string& Form::getName( void ) const {
	return this->Name_;
}

int Form::getGradeToSign( void ) const {
	return this->GradeToSign_;
}

int Form::getGradeToExecute( void ) const {
	return this->GradeToExecute_;
}

bool Form::getSignState( void ) const {
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

void Form::beSigned(const Bureaucrat& b) {
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
	}
	return true;
}

std::ostream& operator<<(std::ostream& stream, const Form& f) {
	stream	<< f.getName()
			<< " could be signed with a minimum grade of " << f.getGradeToSign()
			<< " and execute with a minimum grade of " << f.getGradeToExecute()
			<< (f.getSignState() ? " and is already signed" : " and is not already signed");
	return stream;
}
