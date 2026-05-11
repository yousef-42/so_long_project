/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:04:41 by yasmail           #+#    #+#             */
/*   Updated: 2025/12/29 19:25:21 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ultoa_hex(unsigned long n, int uppercase)
{
	char			*hex;
	char			*digits;
	unsigned long	tmp;
	int				len;

	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	tmp = n;
	len = 1;
	while (tmp > 15 && len++)
		tmp /= 16;
	hex = malloc(len + 1);
	if (!hex)
		return (NULL);
	hex[len] = '\0';
	while (len--)
	{
		hex[len] = digits[n % 16];
		n /= 16;
	}
	return (hex);
}
