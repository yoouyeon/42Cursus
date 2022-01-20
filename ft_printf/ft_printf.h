/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoon <jeyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 02:41:44 by jeyoon            #+#    #+#             */
/*   Updated: 2022/01/20 02:41:48 by jeyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_format(char option, va_list ap);

int		ft_printf_char(va_list ap);
int		ft_printf_str(va_list ap);
int		ft_printf_pointer(va_list ap);
int		ft_printf_deci(char option, va_list ap);
int		ft_printf_hexa(char option, va_list ap);

void	ft_putdeci(int nbr, int *len);
void	ft_putudeci(unsigned int nbr, int *len);
void	ft_puthexa(unsigned int nbr, int *len, char option);
void	ft_puthexa_p(unsigned long nbr, int *len);

#endif
