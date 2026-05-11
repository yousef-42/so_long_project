/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:21:27 by yasmail           #+#    #+#             */
/*   Updated: 2025/11/08 16:26:31 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_itoa_check(va_list args)
{
	int		n;
	char	*string;
	int		len;

	n = va_arg(args, int);
	string = ft_itoa(n);
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
