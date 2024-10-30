/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:48:17 by kbrener-          #+#    #+#             */
/*   Updated: 2024/10/30 14:48:51 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
Fixed	c(3);
Fixed	d(8);
std::cout<<"c = "<<c<<" and d = "<<d<<std::endl;
std::cout<<"c < d = "<<( c < d )<<std::endl;
std::cout<<"c > d = "<<( c > d )<<std::endl;
std::cout<<"c >= d = "<<( c >= d )<<std::endl;
std::cout<<"c <= d = "<<( c <= d )<<std::endl;
std::cout<<"c == d = "<<( c == d )<<std::endl;
std::cout<<"c != d = "<<( c != d )<<std::endl;
std::cout<<"c + d = "<<( c + d )<<std::endl;
std::cout<<"c - d = "<<( c - d )<<std::endl;
std::cout<<"c * d = "<<( c * d )<<std::endl;
std::cout<<"c / d = "<<( c / d )<<std::endl;
std::cout <<"a = "<< a << std::endl;
std::cout <<"pre-increment a : a = "<< ++a << std::endl;
std::cout <<"a = "<< a << std::endl;
std::cout <<"post-increment a : a = "<< a++ << std::endl;
std::cout <<"a = "<< a << std::endl;
std::cout <<"pre-decrement a : a = "<< --a << std::endl;
std::cout <<"a = "<< a << std::endl;
std::cout <<"post-decrement a : a = "<< a-- << std::endl;
std::cout <<"a = "<< a << std::endl;
std::cout << b << std::endl;
std::cout <<"max between a and b = "<< Fixed::max( a, b ) << std::endl;
std::cout <<"min between a and b = "<< Fixed::min( a, b ) << std::endl;
return 0;
}
