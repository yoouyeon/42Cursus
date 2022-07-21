/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 10:41:03 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/21 15:06:55 by jeyoon           ###   ########seoul.kr  */
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
		Fixed(const Fixed &fix);
		Fixed &operator=(Fixed const &fixed);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
