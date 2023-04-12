/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:58:06 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/12 23:03:45 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
class Form;

class Bureaucrat {

public:
	Bureaucrat( void );
	Bureaucrat( const std::string Name, const int Grade );
	Bureaucrat( const  Bureaucrat& other);
	Bureaucrat& operator=( const Bureaucrat& other);
	virtual ~Bureaucrat( void );

	const std::string&	getName( void ) const;
	int					getGrade( void ) const;

	void				incrementGrade( void );
	void				decrementGrade( void );

	void				signForm(Form& f) const;

	class GradeTooHighException: public std::exception {
		public:
			virtual const char* what( void ) const throw();
	};
	class GradeTooLowException: public std::exception {
		public:
			virtual const char* what( void ) const throw();
	};

private:
	const std::string	Name_;
	int					Grade_;
	const static int	LOWEST_GRADE_ = 150;
	const static int	HIGHEST_GRADE_ = 1;

};

std::ostream& operator<<(std::ostream&, const Bureaucrat& b);

#endif
