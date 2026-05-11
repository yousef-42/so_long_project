/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_checked.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:56:37 by yasmail           #+#    #+#             */
/*   Updated: 2025/11/08 17:09:13 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd_checked(char *s, int fd)
{
	int	len;
	int	ret;

	if (!s)
		return (0);
	len = ft_strlen(s);
	ret = write(fd, s, len);
	if (ret != len)
		return (-1);
	return (len);
}
