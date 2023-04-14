/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:58:06 by pfrances          #+#    #+#             */
/*   Updated: 2023/04/12 15:47:24 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
class AForm;

class Intern {

public:
	Intern( void );
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	virtual ~Intern( void );

	AForm *makeForm(const std::string Form_Name, const std::string Target) const;

};

#endif
