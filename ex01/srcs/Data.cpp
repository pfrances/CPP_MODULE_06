/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:19:29 by pfrances          #+#    #+#             */
/*   Updated: 2023/05/04 19:23:45 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::~Data(void) {
	
}

uintptr_t	Data::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Data::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
