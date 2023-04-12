/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:58:06 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/12 22:07:25 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
class Bureaucrat;

class Form {
public:
	Form( void );
	Form( std::string Name, int GradeToSign, int GradeToExecute );
	Form(const Form& other);
	Form& operator=(const Form& other);
	virtual ~Form( void );

	const std::string&	getName( void ) const;
	int					getGradeToSign( void ) const;
	int					getGradeToExecute( void ) const;
	bool				getSignState( void ) const;

	void				beSigned(const Bureaucrat& b);

	virtual void		execute(const Bureaucrat& executor) const = 0;
	bool				checkRequirement(Bureaucrat const & b) const;

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
	class IsNotSignedException: public std::exception {
		public:
			virtual const char* what() const throw();
	};

private:
	std::string	const	Name_;
	const int			GradeToSign_;
	const int			GradeToExecute_;
	bool				IsSigned_;
	const static int	LOWEST_GRADE_ = 150;
	const static int	HIGHEST_GRADE_ = 1;

};

std::ostream& operator<<(std::ostream&, const Form& f);

#endif
