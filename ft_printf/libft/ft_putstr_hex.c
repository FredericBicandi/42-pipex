/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 21:17:37 by fbicandy          #+#    #+#             */
/*   Updated: 2024/06/30 19:00:43 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <stdio.h>

int	ft_putstr_hex(va_list args)
{
	uintptr_t			addr;
	void				*ptr;
	char				hex[17];
	int					count;
	int					i;

	ptr = va_arg(args, void *);
	addr = (uintptr_t)ptr;
	count = 0;
	i = 16;
	if (ptr == NULL)
		return (ft_putstr_fd("(nil)", 1));
	hex[i--] = '\0';
	if (addr == 0)
		hex[i--] = '0';
	while (addr != 0)
	{
		hex[i--] = "0123456789abcdef"[addr % 16];
		addr /= 16;
	}
	count += ft_putstr_fd("0x", 1);
	count += ft_putstr_fd(hex + i +1, 1);
	return (count);
}
