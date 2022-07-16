/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:59:34 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/13 19:18:26 by jeyoon           ###   ########seoul.kr  */
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