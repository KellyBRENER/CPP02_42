/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:09:32 by kbrener-          #+#    #+#             */
/*   Updated: 2024/10/28 16:36:59 by kbrener-         ###   ########.fr       */
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
		Fixed&	operator=(const Fixed& rhs);
		~Fixed(void);

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
