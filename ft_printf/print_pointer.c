/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:55:04 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/13 18:02:45 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int	print_pointer(void *ptr)
{
	char			*hex;
	unsigned long	addr;
	int				len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	addr = (unsigned long)ptr;
	hex = ft_ultoa_hex(addr, 0);
	if (!hex)
		return (-1);
	if (ft_putstr_fd_checked("0x", 1) < 0)
	{
		free(hex);
		return (-1);
	}
	len = 2;
	if (ft_putstr_fd_checked(hex, 1) < 0)
	{
		free(hex);
		return (-1);
	}
	len += ft_strlen(hex);
	free(hex);
	return (len);
}
