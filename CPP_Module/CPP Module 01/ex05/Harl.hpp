/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:49:47 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/13 19:02:50 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
{
private:
	void (Harl::*fp[4])(void);
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	Harl(void);
	void complain(std::string level);
};

#endif