/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:09:32 by kbrener-          #+#    #+#             */
/*   Updated: 2024/10/28 14:32:31 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>


#ifndef FIXED_HPP
#define FIXED_HPP
class	Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed& fCpy);
		Fixed&	operator=(const Fixed& rhs);
		~Fixed(void);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
	private:
		int					_integer;
		static int const	_bits;
} ;

#endif
