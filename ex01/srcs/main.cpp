/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:38:04 by pfrances          #+#    #+#             */
/*   Updated: 2023/05/04 19:22:23 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"

int	main(void) {

	Data data;
	data.x = 42;
	data.y = 21;
	std::cout << "data.x: " << data.x << std::endl;
	std::cout << "data.y: " << data.y << std::endl;
	std::cout << std::endl;

	uintptr_t	serialized_data = Data::serialize(&data);
	std::cout << "&data " << &data << std::endl;
	std::cout << "serialized_data " << std::hex << serialized_data << std::dec << std::endl;
	std::cout << std::endl;

	Data* deserialized_data = Data::deserialize(serialized_data);
	std::cout << std::endl;
	std::cout << "deserialized_data->x: " << deserialized_data->x << std::endl;
	std::cout << "deserialized_data->y: " << deserialized_data->y << std::endl;
	std::cout << "deserialized_data " << deserialized_data << std::endl;
	std::cout << std::endl;

	data.x = 123;
	data.y = 456;

	std::cout << "data.x: " << data.x << std::endl;
	std::cout << "data.y: " << data.y << std::endl;
	std::cout << "deserialized_data->x: " << deserialized_data->x << std::endl;
	std::cout << "deserialized_data->y: " << deserialized_data->y << std::endl;

	return 0;
}
