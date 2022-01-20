/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 02:42:27 by jeyoon            #+#    #+#             */
/*   Updated: 2022/01/20 02:42:30 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	return (write(1, &c, 1));
}

int	ft_printf_str(va_list ap)
{
	char	*s;
	int		i;

	s = va_arg(ap, char *);
	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_printf_pointer(va_list ap)
{
	unsigned long	ul;
	int				ret;

	ul = va_arg(ap, unsigned long);
	ret = write(1, "0x", 2);
	ft_puthexa_p(ul, &ret);
	return (ret);
}

int	ft_printf_deci(char option, va_list ap)
{
	int				i;
	unsigned int	ui;
	int				ret;

	ret = 0;
	if (option == 'd' || option == 'i')
	{
		i = va_arg(ap, int);
		ft_putdeci(i, &ret);
	}
	else
	{
		ui = va_arg(ap, unsigned int);
		ft_putudeci(ui, &ret);
	}
	return (ret);
}

int	ft_printf_hexa(char option, va_list ap)
{
	unsigned int	ui;
	int				ret;

	ret = 0;
	ui = va_arg(ap, unsigned int);
	ft_puthexa(ui, &ret, option);
	return (ret);
}
