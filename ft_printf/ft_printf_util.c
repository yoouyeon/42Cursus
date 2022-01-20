/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 02:42:06 by jeyoon            #+#    #+#             */
/*   Updated: 2022/01/20 02:42:09 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putdeci(int nbr, int *len)
{
	char	*digit;

	digit = "0123456789";
	if (nbr == -2147483648)
	{
		*len += write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		*len += write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= 10)
		ft_putdeci(nbr / 10, len);
	*len += write(1, &digit[nbr % 10], 1);
	return ;
}

void	ft_putudeci(unsigned int nbr, int *len)
{
	char	*digit;

	digit = "0123456789";
	if (nbr >= 10)
		ft_putudeci(nbr / 10, len);
	*len += write(1, &digit[nbr % 10], 1);
	return ;
}

void	ft_puthexa(unsigned int nbr, int *len, char option)
{
	char	*ldigit;
	char	*udigit;

	ldigit = "0123456789abcdef";
	udigit = "0123456789ABCDEF";
	if (nbr >= 16)
		ft_puthexa(nbr / 16, len, option);
	if (option == 'X')
		*len += write(1, &udigit[nbr % 16], 1);
	else
		*len += write(1, &ldigit[nbr % 16], 1);
}

void	ft_puthexa_p(unsigned long nbr, int *len)
{
	char	*digit;

	digit = "0123456789abcdef";
	if (nbr >= 16)
		ft_puthexa_p(nbr / 16, len);
	*len += write(1, &digit[nbr % 16], 1);
}
