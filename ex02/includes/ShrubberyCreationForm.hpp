/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:58:06 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/12 15:37:48 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "Form.hpp"
# include <fstream>
# include <iostream>

class ShrubberyCreationForm : public Form {
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	virtual	~ShrubberyCreationForm( void );

	std::string	getTarget( void ) const;

	void		execute(Bureaucrat const & executor) const;

private:
	std::string			Target_;
	const static int	GRADE_TO_SIGN_ = 145;
	const static int	GRADE_TO_EXECUTE_ = 137;
};

#endif
