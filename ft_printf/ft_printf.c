/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:01:56 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/08 17:33:29 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexa_format(va_list args, const char format)
{
	int				count;
	unsigned int	num;

	count = 0;
	if (format == 'x')
	{
		num = va_arg(args, unsigned int);
		return (ft_putnbr_hex(num, 0));
	}
	if (format == 'X')
	{
		num = va_arg(args, unsigned int);
		return (ft_putnbr_hex(num, 1));
	}
	if (format == 'p')
		return (ft_putstr_hex(args));
	return (count);
}

int	char_format(va_list args, const char format)
{
	int		count;
	char	*str;

	count = 0;
	if (format == 'c')
		count = ft_putchar_fd(va_arg(args, int), 1);
	if (format == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			count = ft_putstr_fd("(null)", 1);
		else
			count = ft_putstr_fd(str, 1);
	}
	return (count);
}

int	nbr_format(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'd' || format == 'i')
		count = ft_putnbr_fd(va_arg(args, int), 1, 0);
	if (format == 'u')
		count = ft_u_putnbr_fd(va_arg(args, int), 1, 0);
	return (count);
}

int	check_format(va_list args, const char format)
{
	if (format == 'd' || format == 'i' || format == 'u')
		return (nbr_format(args, format));
	if (format == 'c' || format == 's')
		return (char_format(args, format));
	if (format == 'p' || format == 'x' || format == 'X')
		return (hexa_format(args, format));
	if (format == '%')
	{
		ft_putchar_fd(format, 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *PARAM, ...)
{
	size_t	count;
	va_list	args;
	size_t	i;

	i = 0;
	count = 0;
	va_start(args, PARAM);
	while (PARAM[i] != '\0')
	{
		if (PARAM[i] == '%')
		{
			i++;
			count += check_format(args, PARAM[i]);
		}
		else
		{
			ft_putchar_fd(PARAM[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
