/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:57:59 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/12 22:54:52 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat( void ) : Name_("Default name"), Grade_(LOWEST_GRADE_) {
	std::cout << "[Bureaucrat] default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat( const std::string Name, const int Grade ) : Name_(Name), Grade_(Grade) {
	if (this->Grade_ < HIGHEST_GRADE_)
		throw Bureaucrat::GradeTooHighException();
	else if (this->Grade_ > LOWEST_GRADE_)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "[Bureaucrat] typed constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : Name_(other.Name_), Grade_(other.Grade_) {
	std::cout << "[Bureaucrat] copy constructor called." << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->Grade_ = other.getGrade();
	}
	std::cout << "[Bureaucrat] asignment called." << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat( void ) {
	std::cout << "[Bureaucrat] destructor called." << std::endl;
}

const std::string& Bureaucrat::getName( void ) const {
	return this->Name_;
}

int Bureaucrat::getGrade( void ) const {
	return this->Grade_;
}

const char* Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return "Grade is too low";
}

const char* Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return "Grade is too high";
}

void Bureaucrat::incrementGrade( void ) {
	if (this->getGrade() > HIGHEST_GRADE_) {
		this->Grade_--;
	}
	else {
		throw Bureaucrat::GradeTooHighException();
	}
}

void Bureaucrat::decrementGrade( void ) {
	if (this->getGrade() < LOWEST_GRADE_) {
		this->Grade_++;
	} else {
		throw Bureaucrat::GradeTooLowException();
	}
}

void Bureaucrat::signForm(Form& f) const {
	try {
		f.beSigned(*this);
		std::cout << this->Name_ << " signed " << f.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << this->Name_ << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const Form& f) const {
	try {
		f.execute(*this);
		std::cout << this->getName() << " executed " << f.getName() << std::endl;
	} catch (std::exception& e ) {
		std::cerr << this->getName() << " couldn't execute " << f.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& b) {
	stream << b.getName() << ", bureaucrat grade " << b.getGrade();
	return stream;
}
