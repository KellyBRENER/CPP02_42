/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:25:34 by kbrener-          #+#    #+#             */
/*   Updated: 2024/10/30 14:47:47 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_bits = 8;

/*CONSTRUCTOR / DESTRUCTOR*/
Fixed::Fixed(void) : _integer(0) {}

Fixed::Fixed(const Fixed& fCpy) {
	*this = fCpy;
}
/*Un constructeur prenant un entier constant en paramètre
 et qui convertit celui-ci en virgule fixe*/
Fixed::Fixed(const int n) {
	_integer = n << _bits;
}

/*Un constructeur prenant un flottant constant en paramètre
et qui convertit celui-ci en virgule fixe.*/
Fixed::Fixed(const float f) {
	_integer = roundf(f * (1 << _bits));
}

Fixed::~Fixed(void) {
}
/*GETTER / SETTER*/
int	Fixed::getRawBits(void) const {
	return (_integer);
}

void	Fixed::setRawBits(int const raw) {
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
	_integer = rhs.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed& rhs) {
	return (_integer > rhs.getRawBits());
}
bool	Fixed::operator<(const Fixed& rhs) {
	return (_integer < rhs.getRawBits());
}
bool	Fixed::operator>=(const Fixed& rhs){
	return (_integer >= rhs.getRawBits());
}
bool	Fixed::operator<=(const Fixed& rhs){
	return (_integer <= rhs.getRawBits());
}
bool	Fixed::operator==(const Fixed& rhs){
	return (_integer == rhs.getRawBits());
}
bool	Fixed::operator!=(const Fixed& rhs){
	return (_integer != rhs.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& rhs) {
	Fixed	sum;
	sum.setRawBits(_integer + rhs.getRawBits());
	return sum;
}
Fixed	Fixed::operator-(const Fixed& rhs) {
	Fixed	sub;
	sub.setRawBits(_integer - rhs.getRawBits());
	return sub;
}
Fixed	Fixed::operator*(const Fixed& rhs) {
	Fixed	mult;
	mult.setRawBits((_integer * rhs.getRawBits()) >> _bits);
	return mult;
}
Fixed	Fixed::operator/(const Fixed& rhs) {
	Fixed	div;
	div.setRawBits((_integer << _bits) / rhs.getRawBits());
	return div;
}
/*pre-incrementation*/
Fixed&	Fixed::operator++() {
	_integer += 1;
	return (*this);
}

/*post-incrementation*/
Fixed	Fixed::operator++(int) {
	Fixed	temp(*this);
	_integer += 1;
	return (temp);
}

/*pre-decrementation*/
Fixed&	Fixed::operator--() {
	_integer -= 1;
	return (*this);
}

/*post-decrementation*/
Fixed	Fixed::operator--(int) {
	Fixed	temp(*this);
	_integer -= 1;
	return (temp);
}

/*utilisation de l'operateur ternaire '?' :
condition ? valeur_si_vrai : valeur_si_faux*/
Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

/*STREAM OPERATOR*/
std::ostream&	operator<<(std::ostream& o, const Fixed& rhs) {
	o<<rhs.toFloat();
	return o;
}
