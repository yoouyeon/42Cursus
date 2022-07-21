/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:48:25 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/21 16:20:41 by jeyoon           ###   ########seoul.kr  */
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

		bool operator<(Fixed const &fixed) const;
		bool operator>(Fixed const &fixed) const;
		bool operator>=(Fixed const &fixed) const;
		bool operator<=(Fixed const &fixed) const;
		bool operator==(Fixed const &fixed) const;
		bool operator!=(Fixed const &fixed) const;

		Fixed operator+(Fixed const &fixed) const;
		Fixed operator-(Fixed const &fixed) const;
		Fixed operator*(Fixed const &fixed) const;
		Fixed operator/(Fixed const &fixed) const;

		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		static Fixed &min(Fixed &f1, Fixed &f2);
		static const Fixed &min(Fixed const &f1, Fixed const &f2);
		static Fixed &max(Fixed &f1, Fixed &f2);
		static const Fixed &max(Fixed const &f1, Fixed const &f2);
};

std::ostream &	operator<<(std::ostream &c, const Fixed &fixed);

#endif
