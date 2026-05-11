/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:48:41 by yasmail           #+#    #+#             */
/*   Updated: 2025/11/08 16:53:54 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uitoa_check(const char *str, va_list args)
{
	char			*string;
	unsigned int	nl;
	int				len;

	if (*str == 'X')
		nl = 1;
	else
		nl = 0;
	string = ft_ultoa_hex(va_arg(args, unsigned int), nl);
	if (!string)
		return (-1);
	len = ft_strlen(string);
	if (ft_putstr_fd_checked(string, 1) < 0)
	{
		free(string);
		return (-1);
	}
	free(string);
	return (len);
}
