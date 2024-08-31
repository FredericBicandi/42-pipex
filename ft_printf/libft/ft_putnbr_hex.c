/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:17:43 by fbicandy          #+#    #+#             */
/*   Updated: 2024/06/30 19:00:16 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hex(unsigned int num, int isupper)
{
	char	*hex_digits;
	char	hex[9];
	int		count;
	int		i;

	hex_digits = "0123456789abcdef";
	if (isupper)
		hex_digits = "0123456789ABCDEF";
	i = 8;
	count = 0;
	hex[i] = '\0';
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	while (num > 0)
	{
		count++;
		hex[--i] = hex_digits[num % 16];
		num /= 16;
	}
	ft_putstr_fd(&hex[i], 1);
	return (count);
}
