/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:52:09 by jeyoon            #+#    #+#             */
/*   Updated: 2022/07/11 13:47:55 by jeyoon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <string>

namespace phonebookutils
{
	void GetInputWithPrompt(std::string prompt, std::string *input_str);
	void GetInputWithPrompt(std::string prompt, int *input_num);
	void FormattedPrint(std::string str);
}

#endif
