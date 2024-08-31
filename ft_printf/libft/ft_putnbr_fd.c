/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:41:10 by fbicandy          #+#    #+#             */
/*   Updated: 2024/06/29 18:40:36 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

int	ft_putnbr_fd(int nbr, int fd, size_t count)
{
	char	n;

	if (nbr == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	if (nbr < 0)
	{
		count++;
		ft_putstr_fd("-", fd);
		nbr = -nbr;
	}
	if (nbr >= 10)
		count = ft_putnbr_fd(nbr / 10, fd, count);
	n = nbr % 10 + '0';
	count++;
	ft_putchar_fd(n, fd);
	return (count);
}
