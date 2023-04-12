/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:58:06 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/12 12:04:03 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
class Form;
# include "Bureaucrat.hpp"


class Form {

public:
	Form( void );
	Form( std::string Name, int GradeToSign, int GradeToExecute );
	Form(const Form& other);
	Form& operator=(const Form& other);
	virtual ~Form( void );

	std::string	getName( void ) const;
	int			getGradeToSign( void ) const;
	int			getGradeToExecute( void ) const;
	bool		getSignState( void ) const;

	void	beSigned(Bureaucrat& b);

	class GradeTooHighException: public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class IsAlreadySignedException: public std::exception {
		public:
			virtual const char* what() const throw();
	};

private:
	std::string	const	Name_;
	int					GradeToSign_;
	int					GradeToExecute_;
	bool				IsSigned_;
	const static int	LOWEST_GRADE_ = 150;
	const static int	HIGHEST_GRADE_ = 1;

};

#endif
