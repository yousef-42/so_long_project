/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:27:56 by yasmail           #+#    #+#             */
/*   Updated: 2025/12/29 19:42:56 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string_check(va_list args)
{
	char	*string;
	int		len;

	string = va_arg(args, char *);
	if (!string)
		string = "(null)";
	len = ft_strlen(string);
	if (ft_putstr_fd_checked(string, 1) < 0)
		return (-1);
	return (len);
}
