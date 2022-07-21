/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:21:18 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/21 15:11:50 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int _value;
		static const int _frac_bits;

	public:
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(const Fixed &fix);
		Fixed &operator=(Fixed const &fixed);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &	operator<<(std::ostream &c, const Fixed &fixed);

#endif
