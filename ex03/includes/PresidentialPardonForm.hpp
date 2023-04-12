/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:54:47 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/12 22:41:14 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form {
public:
	PresidentialPardonForm( void );
	PresidentialPardonForm( const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	virtual	~PresidentialPardonForm( void );

	const std::string&	getTarget( void ) const;

	void				execute(const Bureaucrat& executor) const;

private:
	std::string			Target_;
	const static int	GRADE_TO_SIGN_ = 25;
	const static int	GRADE_TO_EXECUTE_ = 5;
};

#endif
