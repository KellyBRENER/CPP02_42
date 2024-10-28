/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:09:32 by kbrener-          #+#    #+#             */
/*   Updated: 2024/10/28 16:49:35 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <cmath>


#ifndef FIXED_HPP
#define FIXED_HPP
class	Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed& fCpy);
		Fixed(const int n);
		Fixed(const float f);
		~Fixed(void);

		Fixed&	operator=(const Fixed& rhs);

		bool	operator>(const Fixed& rhs);
		bool	operator<(const Fixed& rhs);
		bool	operator>=(const Fixed& rhs);
		bool	operator<=(const Fixed& rhs);
		bool	operator==(const Fixed& rhs);
		bool	operator!=(const Fixed& rhs);

		Fixed	operator+(const Fixed& rhs);
		Fixed	operator-(const Fixed& rhs);
		Fixed	operator*(const Fixed& rhs);
		Fixed	operator/(const Fixed& rhs);

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);

		float	toFloat( void ) const;//convertit la valeur en virgule fixe en nombre à virgule flottante.
		int		toInt( void ) const;//qui convertit la valeur en virgule fixe en nombre entier.
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
	private:
		int					_integer;
		static int const	_bits;
} ;

std::ostream&	operator<<(std::ostream& o, const Fixed& rhs) ;

#endif
