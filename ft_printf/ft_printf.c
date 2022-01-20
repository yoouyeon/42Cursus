/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 02:40:55 by jeyoon            #+#    #+#             */
/*   Updated: 2022/01/20 02:40:58 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char option, va_list ap)
{
	int	len;

	if (option == 'c')
		len = ft_printf_char(ap);
	else if (option == 's')
		len = ft_printf_str(ap);
	else if (option == 'p')
		len = ft_printf_pointer(ap);
	else if (option == 'd' || option == 'i' || option == 'u')
		len = ft_printf_deci(option, ap);
	else if (option == 'X' || option == 'x')
		len = ft_printf_hexa(option, ap);
	else if (option == '%')
	{
		write(1, "%", 1);
		len = 1;
	}
	else
		len = -1;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	int		i;
	int		temp;
	va_list	ap;

	va_start(ap, format);
	i = -1;
	ret = 0;
	while (format[++i] != '\0')
	{
		if (format[i] != '%')
		{
			ret += write(1, &format[i], 1);
			continue ;
		}
		temp = ft_format(format[++i], ap);
		if (temp == -1)
		{
			ret = -1;
			break ;
		}
		ret += temp;
	}
	va_end(ap);
	return (ret);
}
