/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:38:04 by pfrances          #+#    #+#             */
/*   Updated: 2023/05/04 11:28:53 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Classes.hpp"

int	main(void) {
	srand(time(NULL));

	for (int i = 0; i < 5; i++) {
		Base* base = generate();
		identify(base);
		identify(*base);
		delete base;
		std::cout << std::endl;
	}
	return 0;
}
