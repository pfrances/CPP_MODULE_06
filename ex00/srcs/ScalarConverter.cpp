/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:57:59 by pfrances          #+#    #+#             */
/*   Updated: 2023/05/04 11:53:11 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <string>
#include <limits>

enum e_type {
	_char,
	_int,
	_float,
	_double,
	error
};

static bool	is_char(std::string& str) {
	if (str.length() == 1 && !std::isdigit(str[0]))
		return true;
	else if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return true;
	else
		return false;
}

static bool	is_int(std::string& str) {
	if (std::isdigit(str[0]) || str[0] == '-' || str[0] == '+') {
		for (size_t i = 1; i < str.length(); i++) {
			if (!std::isdigit(str[i]))
				return false;
		}
		try {
			std::stoi(str);
		} catch (std::exception& e) {
			return false;
		}
		return true;
	}
	else
		return false;
}

static bool	isPseudoLiteral(std::string& str) {
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return true;
	else
		return false;
}

static bool	is_float(std::string& str) {
	if (isPseudoLiteral(str) && str[str.length() - 1] == 'f')
		return true;
	else if (std::isdigit(str[0]) || str[0] == '-' || str[0] == '+') {
		bool	has_dot = false;
		for (size_t i = 1; i < str.length() - 1; i++) {
			if (!std::isdigit(str[i]) && str[i] != '.')
				return false;
			if (str[i] == '.') {
				if (has_dot)
					return false;
				has_dot = true;
			}
		}
		if (str[str.length() - 1] == 'f') {
			try {
				std::stof(str);
			} catch (std::exception& e) {
				return false;
			}
			return true;
		}
	}
	return false;
}

static bool	is_double(std::string& str) {
	if (isPseudoLiteral(str) && str[str.length() - 1] != 'f')
		return true;
	else if (std::isdigit(str[0]) || str[0] == '-' || str[0] == '+') {
		bool	has_dot = false;
		for (size_t i = 1; i < str.length(); i++) {
			if (!std::isdigit(str[i]) && str[i] != '.')
				return false;
			if (str[i] == '.') {
				if (has_dot)
					return false;
				has_dot = true;
			}
		}
		try {
			std::stod(str);
		} catch (std::exception& e) {
			return false;
		}
		return true;
	}
	return false;
}

static e_type	get_type(std::string& str){
	if (is_char(str))
		return _char;
	else if (is_int(str))
		return _int;
	else if (is_float(str))
		return _float;
	else if (is_double(str))
		return _double;
	else
		return error;
}

void ScalarConverter::convert(const std::string& str) {
	char char_value;
	int int_value;
	float float_value;
	double double_value;

	switch (get_type(const_cast<std::string&>(str)))
	{
		case _char:
			char_value = str[0];
			int_value = static_cast<int>(char_value);
			float_value = static_cast<float>(char_value);
			double_value = static_cast<double>(char_value);
			break;
		case _int:
			int_value = std::stoi(str);
			char_value = static_cast<char>(int_value);
			float_value = static_cast<float>(int_value);
			double_value = static_cast<double>(int_value);
			break;
		case _float:
			float_value = std::stof(str);
			char_value = static_cast<char>(float_value);
			int_value = static_cast<int>(float_value);
			double_value = static_cast<double>(float_value);
			break;
		case _double:
			double_value = std::stod(str);
			char_value = static_cast<char>(double_value);
			int_value = static_cast<int>(double_value);
			float_value = static_cast<float>(double_value);
			break;
		default:
			std::cout << "Invalid input" << std::endl;
		return;
	}
	if (std::isprint(char_value))
		std::cout << "char: '" << char_value << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (double_value < std::numeric_limits<int>::min() || double_value > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << int_value << std::endl;
	if (float_value - static_cast<int>(float_value) == 0.0f)
		std::cout << "float: " << float_value << ".0f" << std::endl;
	else
		std::cout << "float: " << float_value << "f" << std::endl;
	if (double_value == static_cast<int>(double_value))
		std::cout << "double: " << double_value << ".0" << std::endl;
	else
		std::cout << "double: " << double_value << std::endl;
}
