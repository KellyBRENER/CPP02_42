/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:25:34 by kbrener-          #+#    #+#             */
/*   Updated: 2024/10/28 17:02:53 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Fixed.hpp"

int const Fixed::_bits = 8;

/*CONSTRUCTOR / DESTRUCTOR*/
Fixed::Fixed(void) : _integer(0) {
	std::cout<<"default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& fCpy) {
	std::cout<<"copy constructor called"<<std::endl;
	*this = fCpy;
}
/*Un constructeur prenant un entier constant en paramètre
 et qui convertit celui-ci en virgule fixe*/
Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	_integer = n << _bits;
}

/*Un constructeur prenant un flottant constant en paramètre
et qui convertit celui-ci en virgule fixe.*/
Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	_integer = roundf(f * (1 << _bits));
}

Fixed::~Fixed(void) {
	std::cout<<"destructor called"<<std::endl;
}
/*GETTER / SETTER*/
int	Fixed::getRawBits(void) const {
	return (_integer);
}

void	Fixed::setRawBits(int const raw) {
	std::cout<<"setRawBits member function called"<<std::endl;
	_integer = raw;
}

/*MEMEBER FUNCTION*/
float	Fixed::toFloat( void ) const {
	return (static_cast<float>(_integer) / 256);
}

int		Fixed::toInt( void ) const {
	return (_integer / 256);
}

/*OPERATOR OVERLOAD*/

Fixed&	Fixed::operator=(const Fixed& rhs) {
	std::cout<<"copy assignment operator called"<<std::endl;
	_integer= rhs.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed& rhs) {
	if (_integer > rhs.getRawBits())
		return true;
	return false;
}
bool	Fixed::operator<(const Fixed& rhs) {
	if (_integer < rhs.getRawBits())
		return true;
	return false;
}
bool	Fixed::operator>=(const Fixed& rhs){
	if (_integer >= rhs.getRawBits())
		return true;
	return false;
}
bool	Fixed::operator<=(const Fixed& rhs){
	if (_integer <= rhs.getRawBits())
		return true;
	return false;
}
bool	Fixed::operator==(const Fixed& rhs){
	if (_integer == rhs.getRawBits())
		return true;
	return false;
}
bool	Fixed::operator!=(const Fixed& rhs){
	if (_integer != rhs.getRawBits())
		return true;
	return false;
}

Fixed	Fixed::operator+(const Fixed& rhs) {
	Fixed	sum(_integer + rhs.getRawBits());
	return sum;
}
Fixed	Fixed::operator-(const Fixed& rhs) {
	Fixed	sub(_integer - rhs.getRawBits());
	return sub;
}
Fixed	Fixed::operator*(const Fixed& rhs) {
	Fixed	mult(_integer * rhs.getRawBits());
	return mult;
}
Fixed	Fixed::operator/(const Fixed& rhs) {
	Fixed	div(_integer / rhs.getRawBits());
	return div;
}

Fixed&	Fixed::operator++();
Fixed	Fixed::operator++(int);
Fixed&	Fixed::operator--();
Fixed	Fixed::operator--(int);

static Fixed&	min(Fixed& a, Fixed& b);
static const Fixed&	min(const Fixed& a, const Fixed& b);
static Fixed&	max(Fixed& a, Fixed& b);
static const Fixed&	max(const Fixed& a, const Fixed& b);

/*STREAM OPERATOR*/
std::ostream&	operator<<(std::ostream& o, const Fixed& rhs) {
	o<<rhs.toFloat();
	return o;
}
