/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:58:06 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/12 15:47:24 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
class Bureaucrat;
# include "Form.hpp"

class Bureaucrat {

public:
	Bureaucrat( void );
	Bureaucrat( std::string Name, int Grade );
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	virtual ~Bureaucrat( void );

	class GradeTooHighException: public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public:
			virtual const char* what() const throw();
	};

	std::string	getName( void ) const throw() ;
	int			getGrade( void ) const throw() ;

	void	incrementGrade( void ) ;
	void	decrementGrade( void ) ;

	void	signForm(Form & f) const throw();
	void	executeForm(Form const & f) const throw() ;


private:
	std::string	const	Name_;
	int					Grade_;
	const static int	LOWEST_GRADE_ = 150;
	const static int	HIGHEST_GRADE_ = 1;

};

std::ostream& operator<<(std::ostream&, const Bureaucrat& Bureaucrat);

#endif
