/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:57:59 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/12 12:09:17 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : Name_("Default name"), Grade_(LOWEST_GRADE_) {
	std::cout << "[Bureaucrat] default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat( std::string Name, int Grade ) : Name_(Name), Grade_(Grade) {
	if (this->Grade_ < HIGHEST_GRADE_)
		this->Grade_ = HIGHEST_GRADE_;
	else if (this->Grade_ > LOWEST_GRADE_)
		this->Grade_ = LOWEST_GRADE_;
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

std::string Bureaucrat::getName( void ) const {
	return this->Name_;
}

int Bureaucrat::getGrade( void ) const {
	return this->Grade_;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

void Bureaucrat::incrementGrade() {
	if (this->getGrade() > HIGHEST_GRADE_) {
		this->Grade_--;
	}
	else {
		throw Bureaucrat::GradeTooHighException();
	}
}

void Bureaucrat::decrementGrade() {
	if (this->getGrade() < LOWEST_GRADE_) {
		this->Grade_++;
	}
	else {
		throw Bureaucrat::GradeTooLowException();
	}
}

void Bureaucrat::signForm(Form& f) {
	try {
		f.beSigned(*this);
		std::cout << this->Name_ << " signed " << f.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << this->Name_ << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& Bureaucrat) {
	stream << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << ".";
	return stream;
}
