/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:13:37 by pfrances          #+#    #+#             */
/*   Updated: 2023/05/04 11:38:52 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"
#include <cstdlib>
#include <iostream>

Base*	generate(void) {
	int	i = rand() % 3;

	if (i == 0) {
		std::cout << "[Generate] A type" << std::endl;
		return reinterpret_cast<Base*>(new A);
	} else if (i == 1) {
		std::cout << "[Generate] B type" << std::endl;
		return reinterpret_cast<Base*>(new B);
	} else {
		std::cout << "[Generate] C type" << std::endl;
		return reinterpret_cast<Base*>(new C);
	}
}

void	identify(Base* p) {
		A* a = dynamic_cast<A*>(p);
		if (a) {
			std::cout << "[(ptr) Identify] p is A type" << std::endl;
			return ;
		}
		B* b = dynamic_cast<B*>(p);
		if (b) {
			std::cout << "[(ptr) Identify] p is B type" << std::endl;
			return ;
		}
		C* c = dynamic_cast<C*>(p);
		if (c) {
			std::cout << "[(ptr) Identify] p is C type" << std::endl;
			return ;
		}
		std::cout << "[(ptr) Identify] p is unknown type" << std::endl;
}

void	identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "[(ref) Identify] p is A type" << std::endl;
		return ;
	} catch (std::exception& e) {
	} try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "[(ref) Identify] p is B type" << std::endl;
		return ;
	} catch (std::exception& e) {
	} try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "[(ref) Identify] p is C type" << std::endl;
		return ;
	} catch (std::exception& e) {
	}
	std::cout << "[(ref) Identify] p is unknown type" << std::endl;
}
