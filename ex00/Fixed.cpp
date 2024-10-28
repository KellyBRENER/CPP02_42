/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:25:34 by kbrener-          #+#    #+#             */
/*   Updated: 2024/10/28 14:57:10 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Fixed.hpp"

int const Fixed::_bits = 8;

Fixed::Fixed(void) : _integer(0) {
	std::cout<<"default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& fCpy) {
	std::cout<<"copy constructor called"<<std::endl;
	*this = fCpy;
}

Fixed&	Fixed::operator=(const Fixed& rhs) {
	std::cout<<"copy assignment operator called"<<std::endl;
	_integer= rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const {
	std::cout<<"getRawBits member function called"<<std::endl;
	return (_integer);
}

void	Fixed::setRawBits(int const raw) {
	std::cout<<"setRawBits member function called"<<std::endl;
	_integer = raw;
}

Fixed::~Fixed(void) {
	std::cout<<"Fixed destructor called"<<std::endl;
}
