/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:01:08 by pfrances          #+#    #+#             */
/*   Updated: 2023/05/04 19:22:33 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <stdint.h>

struct Data {
public:
	~Data(void);
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
	int	x;
	int	y;
};

#endif
